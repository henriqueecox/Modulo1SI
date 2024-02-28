// Versão do compilador
pragma solidity ^0.8.0;

// Contrato para verificar documentos
contract VerificarDocumentos {
    uint256 idade; // Variável de estado para armazenar a idade
    address public owner; // Variável de estado para armazenar o endereço do proprietário do contrato

    // Construtor - é executado apenas uma vez durante a implantação do contrato
    constructor() {
        idade = 18; // Define a idade padrão como 18 anos
        owner = msg.sender; // Atribui o endereço do criador do contrato como proprietário
    }

    // Modificador que permite que apenas o proprietário execute certas funções
    modifier OwnerOnly() {
        require(msg.sender == owner, "Not owner"); // Verifica se é o proprietário
        _; // Permite a execução da função modificada
    }

    // Função para definir a idade, apenas acessível pelo proprietário
    function setIdade(uint256 _idade) external OwnerOnly returns (bool) {
        idade = _idade; // Atualiza a idade
        return true; // Retorna verdadeiro para indicar sucesso
    }

    // Função para obter a idade
    function getIdade() external view returns (uint256) {
        return idade; // Retorna a idade armazenada
    }
}