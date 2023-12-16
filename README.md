# **Labirinth**

## О **Labirinth**

**Labirinth** -- это компьютерная игра, симулирующая лабиринт с препятствиями. Вам предлагается пройти увлекательные и, порой, не самые простые уровни с помощью шарика и виртуальной гравитации! С помощью **Labirinth**, запустив один из загруженных в игре уровней, 
вы, используя клавиатуру, можете стараться пройти лабиринт, не попасть в ловушки и открывать новые карты.

**Labirinth** совершенно бесплатна, что даёт вам доступ ко всем функциям данного приложения.

## Минимальные требования

В целом, для данной игры от компьютера не требуется больших мощностей. Однако стоит отметить, 
что, так как игра была написана на версии *С++14*, то она доступна для *Windows 8+*.

Для запуска вам потребуется версия *С++14*, 
а также *sfml*.

## Установка

Чтобы установить **Labirinth**, вы можете как скачать папку с файлами непосредственно с сайта *GitHub*, так и, при наличии git на вашем компьютере 
(скачать *Git* можно [тут](https://git-scm.com/downloads) или [тут](https://gitforwindows.org/)), воспользоваться следующей командой: 

```
git clone https://github.com/ArturSadykov2/Project_labirint_3sem
```
## Запуск игры
Для запуска игры вы должны запустить файл *main.cpp*. Для этого можете запустить терминал в папке игры и воспользоватся командой 
```
python3 main.cpp
```
При запуске игры вы попадаете в ***главное меню***. Там есть 3 кнопки:

### Exit

При нажатии вы немедленно выходите из игры.

### Settings

Нажимая эту кнопку, вы попадаете в меню настроек, где можете регулировать *вид шарика*. Нажав на **Стрелку в левом верхнем углу**, вы вернётесь в ***главное меню***.

### Go

При нажатии этой кнопки вы начинаете игровой процесс на первом уровне. Сложность уровней возрастает с номером.

После успешного прохождения уровня вы увидете меню с двумя кнопками:
### Go back

Нажимая эту кнопку, вы возвращаетесь в главное меню

### Next level

При нажатии этой кнопки вы переходите на следующий уровень по порядку.

Также в процессе прохождения уровня вы можете нажать на кнопку паузы.

### Pause

Нажимая на **Большую клавишу**, вы останавливаете игру, сохрания текущий прогресс (местоположение шарика). Позже, не закрывая игру, вы можете продолжить прохождение нажав на **Большую клавишу** или кнопку **Continue**.

### Игровой процесс

При запуске уровня открывается карта лабиринта и шарик в точке старта. Используя клавиатуру, вам нужно пройти лабиринт, минуя препятствия, и добраться до финиша. Если вы задените одно из препятствий, то уровень сразу начнется сначала. Кнопками "W", "A", "S", "D" вы придаете шарику ускорения в соответствующем направлении, а при ударе со стенкой он отскакивает. Игра заканчивается, когда вы проходите последний уровень, вы попадаете в главное меню.
