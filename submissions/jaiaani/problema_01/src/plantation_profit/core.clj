(ns plantation-profit.core
  (:require [schema.core :as s])
  (:use clojure.string)
  (:use clojure.java.io)
  (:gen-class))

(def InfosSemente
  {:v s/Int
   :w s/Int})

(defn input
  [example]
  (with-open [rdr (reader (str "./resources/input/" example ".txt"))]
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

(defn output
  [arquivoExemplo]
  (let [input (input (str arquivoExemplo))
        elementos-do-input (elementos-do-input input)
        lista-de-sementes (lista-info-sementes (:vetor-info-sementes elementos-do-input))
        quantidade-de-sementes (first (:primeira-linha elementos-do-input))
        espacos-disponiveis (second (:primeira-linha elementos-do-input))]
    (println (str "O maximo lucro possivel é de R$"
                  (maximo-lucro-possivel quantidade-de-sementes lista-de-sementes espacos-disponiveis)
                  ",00"))))

(defn- exit [status msg]
  (println msg)
  (System/exit status))

(defn -main
  [& args]
  (println "As opcoes sao example1, example2, example3, referentes aos exemplos do projeto")
  (println "Insira aqui o exemplo que voce deseja testar:")
  (-> (read-line)
      output)
  (exit 1 "End"))
