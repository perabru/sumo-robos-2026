# Robô Sumô Arduino com Ultrassônico e Sensores de Faixa

Projeto de um **robô sumô autônomo** utilizando Arduino, ponte H, sensor ultrassônico HC-SR04 e dois sensores TCRT5000 para identificação de faixa branca/preta na arena.

O robô é capaz de:

- Procurar o adversário automaticamente;
- Avançar quando detectar um objeto próximo;
- Detectar a borda da arena;
- Recuar e girar ao encontrar a faixa branca;
- Controlar dois motores DC usando ponte H.

---

## 📌 Objetivo do Projeto

Este projeto tem como objetivo criar um robô simples e funcional para competições de sumô de robôs, utilizando componentes acessíveis e programação em Arduino.

A lógica principal do robô é:

1. Verificar os sensores de faixa;
2. Evitar sair da arena;
3. Medir a distância com o sensor ultrassônico;
4. Atacar o adversário quando ele estiver próximo;
5. Girar procurando o adversário quando ele não for detectado.

---

## 🧰 Componentes Utilizados

| Componente | Quantidade |
|---|---:|
| Arduino Uno | 1 |
| Ponte H / Driver de Motor | 1 |
| Motores DC | 2 |
| Sensor Ultrassônico HC-SR04 | 1 |
| Sensor TCRT5000 | 2 |
| Rodas | 2 |
| Bateria externa | 1 |
| Jumpers | Vários |
| Chassi do robô | 1 |

---

## 🔌 Tabela de Ligações

| Componente | Pino Arduino |
|---|---:|
| IN1 Ponte H | 2 |
| IN2 Ponte H | 3 |
| IN3 Ponte H | 4 |
| IN4 Ponte H | 5 |
| Sensor TCRT5000 esquerdo | 6 |
| Sensor TCRT5000 direito | 7 |
| TRIG Ultrassônico | 9 |
| ECHO Ultrassônico | 10 |
| VCC sensores | 5V |
| GND sensores | GND |

---

## 🖼️ Diagrama da Tabela de Ligações

Adicione a imagem da tabela na pasta do projeto e use:

```markdown
![Tabela de Ligações](tabela-ligacoes.png)
