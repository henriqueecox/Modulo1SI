#include <iostream>
#include <string>
#include <unordered_map>

// Definir a estrutura de dados para os nós da DHT
struct DHTNode {
  std::unordered_map<std::string, std::string> data;
};

// Função de hash para calcular o índice na tabela hash
size_t hashFunction(const std::string &key) {
  return std::hash<std::string>{}(key);
}

// Função para inserir um par chave-valor na DHT
void insert(DHTNode &node, const std::string &key, const std::string &value) {
  size_t index = hashFunction(key);
  node.data[key] = value;
  std::cout << "Inserted key '" << key << "' with value '" << value
            << "' at index " << index << std::endl;
}

// Função para remover um par chave-valor da DHT
void remove(DHTNode &node, const std::string &key) {
  auto it = node.data.find(key);
  if (it != node.data.end()) {
    node.data.erase(it);
    std::cout << "Removed key '" << key << "' from DHT" << std::endl;
  } else {
    std::cout << "Key '" << key << "' not found in DHT" << std::endl;
  }
}

// Função para imprimir todos os pares chave-valor na DHT
void print(const DHTNode &node) {
  std::cout << "DHT Contents:" << std::endl;
  for (const auto &pair : node.data) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
}

int main() {
  // Criar um nó da DHT
  DHTNode node;

  // Teste das operações de inserção, remoção e impressão
  insert(node, "key1", "value1");
  insert(node, "key2", "value2");
  insert(node, "key3", "value3");

  print(node);

  remove(node, "key2");

  print(node);

  return 0;
}
