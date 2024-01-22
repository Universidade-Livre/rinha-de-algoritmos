(ns plantation-profit.english-core
  (:require [clojure.tools.cli :refer [parse-opts]]
            [schema.core :as s])
  (:use clojure.string)
  (:use clojure.java.io)
  (:gen-class))

;The same code, but in an english version :)

(def SeedInfo
  {:v s/Int
   :w s/Int})

(defn input
  [txt-path]
  (with-open [rdr (reader (str txt-path))]
    (doall (mapv vector (line-seq rdr)))))

(s/defn seed-line->seed-vector :- [s/Int s/Int]
  [input-line]
  (mapv #(Integer/parseInt %) (clojure.string/split (first input-line) #"\t")))

(defn input-elements
  [input]
  {:first-line (map #(Integer/parseInt %) (clojure.string/split (first (first input)) #" "))
   :seeds-informations (map #(seed-line->seed-vector %) (remove #{(first input)} input))})

(s/defn wire->model-seed :- SeedInfo
  [seed-vector :- [s/Int s/Int]]
  (let [space-required (first seed-vector)
        value (second seed-vector)]
    {:v value
     :w space-required}))

(s/defn list-of-seeds :- [SeedInfo]
  [seed-vector :- [s/Int s/Int]]
  (mapv #(wire->model-seed %) seed-vector))

(s/defn maximum-possible-profit :- s/Int
  [seeds-qty :- s/Int
   list-of-seeds :- [SeedInfo]
   spaces-available :- s/Int]
  (if (or (zero? seeds-qty) (zero? spaces-available))
    0
    (let [seed (nth list-of-seeds (dec seeds-qty))
          remaining-spaces (- spaces-available (:w seed))]
      (if (> (:w seed) spaces-available)
        (maximum-possible-profit (dec seeds-qty) list-of-seeds spaces-available)
        (max (+ (:v seed) (maximum-possible-profit (dec seeds-qty) list-of-seeds remaining-spaces))
             (maximum-possible-profit (dec seeds-qty) list-of-seeds spaces-available))))))

(defn output [filePath]
  (let [input (input filePath)
        input-elements (input-elements input)
        list-of-seeds (list-of-seeds (:seeds-informations input-elements))
        seeds-qty (first (:first-line input-elements))
        spaces-available (second (:first-line input-elements))]
    (maximum-possible-profit seeds-qty list-of-seeds spaces-available)))

(def cli-options
  ;; An option with a required argument
  [["-f" "--file FILE" "File Path"
    :default "./resources/input/example1.txt"
    :parse-fn #(str %)
    :validate [#(ends-with? % ".txt") "Must be a .txt file"]]
   ["-h" "--help"]])

(defn- error-msg [errors]
  (str "The following errors occurred while parsing your command:\n\n"
       (join \newline errors)))

(defn- exit [status msg]
  (println msg)
  (System/exit status))

(defn -main
  [& args]
  (let [arguments (parse-opts args cli-options)
        options (:options arguments)
        errors (:errors arguments)]
    (cond
      (:help options) (println (:summary arguments))
      errors (exit 1 (error-msg errors))
      :else (let [cli-return (str "Maximum possible profit isR$" (output (:file options)))]
              (println cli-return)))))
