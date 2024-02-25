// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract SimpleDHT {
    mapping(string => string) private data;

    // Função para inserir um par chave-valor na DHT
    function insert(string memory key, string memory value) public {
        data[key] = value;
    }

    // Função para remover um par chave-valor da DHT
    function remove(string memory key) public {
        delete data[key];
    }

    // Função para obter o valor associado a uma chave na DHT
    function getValue(string memory key) public view returns (string memory) {
        return data[key];
    }
}
