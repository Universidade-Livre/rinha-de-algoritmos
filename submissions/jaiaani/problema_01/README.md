# plantation-profit

A Clojure library designed to ... well, that part is up to you.

## Usage
🇧🇷
Para executar o programa siga os seguintes passos:

Usando o docker...
 * Nesse mesmo diretório, rode o comando: `docker build -t problema1 .`
 * Depois rode o comando `docker run --rm -it problema1`
   * Como input há 3 opções: 
      - example1
      - example2
      - example3 
 
   são referentes aos exemplos dados, é somente uma concatenação para se referir
      aos arquivos localizados na pasta ./resources/input,
     ```clojure 
     (defn input
        [example]
        (with-open [rdr (reader (str "./resources/input/" example ".txt"))]
        (doall (mapv vector (line-seq rdr)))))```
   
  se for necessário testar outras entradas, é só adicionar o arquivo nessa pasta.

English -

To run the program, follow these steps:

Using docker...
* In that same directory, run the command: `docker build problema1 .`
* Then run the command `docker run --rm -it problema1`
    * As input there are 3 options:
        - example1
        - example2
        - example3

  refer to the examples given, it is just a concatenation to refer
  to files located in the ./resources/input folder,
    ```clojure 
    (defn input
       [example]
       (with-open [rdr (reader (str "./resources/input/" example ".txt"))]
       (doall (mapv vector (line-seq rdr)))))```

If you need to test other entries, just add the file to this folder.

## License

Copyright © 2024 FIXME

This program and the accompanying materials are made available under the
terms of the Eclipse Public License 2.0 which is available at
http://www.eclipse.org/legal/epl-2.0.

This Source Code may also be made available under the following Secondary
Licenses when the conditions for such availability set forth in the Eclipse
Public License, v. 2.0 are satisfied: GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or (at your
option) any later version, with the GNU Classpath Exception which is available
at https://www.gnu.org/software/classpath/license.html.
