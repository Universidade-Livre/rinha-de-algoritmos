(ns plantation-profit.core-test
  (:require [clojure.test :refer :all]
            [plantation-profit.core :as core]))

(def lista-de-sementes
  [{:v 86 :w 3}
   {:v 80 :w 1}
   {:v 71 :w 3}
   {:v 39 :w 2}
   {:v 53 :w 2}
   {:v 47 :w 3}
   {:v 46 :w 2}
   {:v 32 :w 1}
   {:v 69 :w 1}
   {:v 89 :w 2}
   {:v 58 :w 4}
   {:v 86 :w 3}
   {:v 54 :w 3}
   {:v 53 :w 3}
   {:v 64 :w 1}
   {:v 82 :w 4}
   {:v 46 :w 1}
   {:v 48 :w 2}
   {:v 53 :w 4}
   {:v 68 :w 1}
   {:v 94 :w 3}
   {:v 87 :w 1}])

(deftest maximo-lucro-possivel-test
  (testing
    "Dada a quantidade de sementes, as informacoes da semente e os espacos disponiveis
    deve retornar o maior lucro possivel"
    (is (= (core/maximo-lucro-possivel 22 lista-de-sementes 36)
           1194))))
