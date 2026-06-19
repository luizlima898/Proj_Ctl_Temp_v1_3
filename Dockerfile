# 1. Escolhe a imagem base do Node.js
FROM node:20-alpine

# 2. Instala as dependências necessárias para compilar pacotes nativos (como o canvas)
RUN apk add --no-cache \
    python3 \
    make \
    g++ \
    jpeg-dev \
    cairo-dev \
    pango-dev \
    giflib-dev

# 3. Cria o diretório de trabalho dentro do container
WORKDIR /usr/src/app

# 4. Copia os arquivos de dependências primeiro
COPY package*.json ./

# 5. Instala as dependências da aplicação
RUN npm install

# 6. Copia o restante dos arquivos
COPY . .

# 7. Expõe a porta que o seu server.js utiliza
EXPOSE 3000

# 8. Comando para iniciar a aplicação
CMD ["node", "server.js"]

