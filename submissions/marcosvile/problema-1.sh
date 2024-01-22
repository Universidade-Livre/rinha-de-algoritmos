#!/bin/bash

set -exo pipefail

main() {

    chmod +r "$1"
    
    local arquivo=$1

    if [ "$#" -ne 1 ]; then
        echo "Arquivo de entrada não especificado."
        exit 1
    fi

    if [ ! -e "$arquivo" ]; then
        echo "O arquivo '$arquivo' não existe."
        exit 1
    fi

    calcular_lucro_maximo "$arquivo"
}

calcular_lucro_maximo() {
    local arquivo=$1
    declare -a linhas_array=()

    while IFS= read -r linha; do
        linhas_array+=("$linha")
    done < "$arquivo"

    read -r quantidade_sementes quantidade_espacos <<< "${linhas_array[0]}"

    if [ "$quantidade_sementes" -lt 1 ] || [ "$quantidade_sementes" -gt 1000 ] || \
       [ "$quantidade_espacos" -lt 1 ] || [ "$quantidade_espacos" -gt 2666 ]; then
        echo "Quantidades de sementes ou espaços fora dos limites permitidos."
        exit 1
    fi

    declare -a valores=()
    declare -a espacos_necessarios=()

    for ((i = 1; i <= quantidade_sementes; i++)); do
        read -r espaco_necessario valor <<< "${linhas_array[i]}"
        if [ "$espaco_necessario" -lt 1 ] || [ "$espaco_necessario" -gt 7 ] || \
           [ "$valor" -lt 30 ] || [ "$valor" -gt 200 ]; then
            echo "Valores de espaço necessário ou valor fora dos limites permitidos."
            exit 1
        fi
        espacos_necessarios+=("$espaco_necessario")
        valores+=("$valor")
    done

    declare -a lucro_maximo=()
    for ((i = 0; i <= quantidade_espacos; i++)); do
        lucro_maximo+=("0")
    done

    for ((i = 1; i <= quantidade_sementes; i++)); do
        for ((j = quantidade_espacos; j >= espacos_necessarios[i-1]; j--)); do
            lucro_potencial=$((valores[i-1] + lucro_maximo[j - espacos_necessarios[i-1]]))
            if [ "$lucro_potencial" -gt "${lucro_maximo[j]}" ]; then
                lucro_maximo[j]=$lucro_potencial
            fi
        done
    done

    echo "Lucro máximo usando todas as sementes e espaço possível: ${lucro_maximo[quantidade_espacos]}"
}

main "$@"