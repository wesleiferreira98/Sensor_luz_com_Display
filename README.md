# Sensor_luz_com_Display

# Descrição do Código em C++ para Arduino

## Inclusão de Bibliotecas
O código utiliza as bibliotecas `LiquidCrystal_I2C` para controlar o LCD via I2C e `DHT` para o sensor de temperatura e umidade.

## Definição de Constantes e Objetos
- `pinSen`: Define o pino de leitura do sensor de temperatura e umidade.
- `DHTTYPE`: Define o tipo de sensor DHT (DHT11 neste caso).
- `sensorLuz`: Define o pino de leitura do sensor de luz.
- `lcd`: Objeto para controle do LCD.
- `sensor`: Objeto para controle do sensor de temperatura e umidade DHT.

## Variáveis de Controle de Tempo
- `previousMillis`: Armazena o tempo da última execução.
- `intervalo`: Define o intervalo desejado entre as execuções (10 segundos).

## Configuração Inicial (Setup)
- Inicializa o LCD, configura o pino do sensor de luz como entrada e inicia o sensor de temperatura e umidade.
- Lê os valores iniciais de umidade e temperatura.

## Loop Principal
1. **Leitura do Sensor de Luz:**
   - Lê o valor do sensor de luz e armazena em `info`.

2. **Atualização do LCD:**
   - Chama a função `setLCD()` para atualizar as informações no LCD.

3. **Exibição no LCD:**
   - Se `es` for falso, exibe novamente as informações no LCD e marca `es` como verdadeiro.

4. **Controle de Tempo:**
   - Se passou o intervalo definido, limpa o LCD, reinicia a flag `es` e aguarda 700 milissegundos para melhor visualização.

5. **Controle de Backlight do LCD:**
   - Liga ou desliga o backlight do LCD com base no valor lido do sensor de luz.

## Função `setLCD()`
- Atualiza as informações de temperatura e umidade no LCD.



