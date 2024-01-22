(ns plantation-profit.core
  (:require [clojure.tools.cli :refer [parse-opts]]
            [schema.core :as s])
  (:use clojure.string)
  (:use clojure.java.io)
  (:gen-class))

(def InfosSemente
  {:v s/Int
   :w s/Int})

(defn input
  [txt-path]
  (with-open [rdr (reader (str txt-path))]
    (doall (mapv vector (line-seq rdr)))))

(s/defn linha-semente->vetor-semente :- [s/Int s/Int]
  [linha-input]
  (mapv #(Integer/parseInt %) (clojure.string/split (first linha-input) #"\t")))

(defn elementos-do-input
  [input]
  {:primeira-linha (map #(Integer/parseInt %) (clojure.string/split (first (first input)) #" "))
   :vetor-info-sementes (map #(linha-semente->vetor-semente %) (remove #{(first input)} input))})

(s/defn wire->model-semente :- InfosSemente
  [vetor-semente :- [s/Int s/Int]]
  (let [espaco-necessario (first vetor-semente)
        valor (second vetor-semente)]
    {:v valor
     :w espaco-necessario}))

(s/defn lista-info-sementes :- [InfosSemente]
  [vetor-semente :- [s/Int s/Int]]
  (mapv #(wire->model-semente %) vetor-semente))

(s/defn maximo-lucro-possivel
  [quantidade-sementes :- s/Int
   lista-de-sementes :- [InfosSemente]
   espacos-disponiveis :- s/Int]
  (if (or (zero? quantidade-sementes) (zero? espacos-disponiveis))
    0
    (let [semente (nth lista-de-sementes (dec quantidade-sementes))
          espacos-restantes (- espacos-disponiveis (:w semente))]
      (if (> (:w semente) espacos-disponiveis)
        (maximo-lucro-possivel (dec quantidade-sementes) lista-de-sementes espacos-disponiveis)
        (max (+ (:v semente) (maximo-lucro-possivel (dec quantidade-sementes) lista-de-sementes espacos-restantes))
             (maximo-lucro-possivel (dec quantidade-sementes) lista-de-sementes espacos-disponiveis))))))

(defn output [filePath]
  (let [input (input filePath)
        elementos-do-input (elementos-do-input input)
        lista-de-sementes (lista-info-sementes (:vetor-info-sementes elementos-do-input))
        quantidade-de-sementes (first (:primeira-linha elementos-do-input))
        espacos-disponiveis (second (:primeira-linha elementos-do-input))]
  (maximo-lucro-possivel quantidade-de-sementes lista-de-sementes espacos-disponiveis)))

(def cli-options
  [["-f" "--file FILE" "File Path"
    :default "./resources/input/example1.txt"
    :parse-fn #(str %)
    :validate [#(ends-with? % ".txt") "O arquivo precisa ser .txt"]]
   ["-h" "--help"]])

(defn- error-msg [errors]
  (str "Os seguintes erros ocorreram ao executar seu comando:\n\n"
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
      :else (let [cli-return (str "O máximo lucro possivel é de R$" (output (:file options)))]
              (println cli-return)))))
