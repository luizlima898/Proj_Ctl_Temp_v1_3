-- Garante que o banco de dados existe
CREATE DATABASE IF NOT EXISTS banco.db;
USE banco.db;

-- Cria a tabela exatamente com o nome que você definiu
CREATE TABLE IF NOT EXISTS leituras (
    id INT AUTO_INCREMENT PRIMARY KEY,
    temperatura DECIMAL(5,2) NOT NULL,
    umidade DECIMAL(5,2) NOT NULL
    datahora TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
