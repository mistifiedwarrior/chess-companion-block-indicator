# Chess-companion Block Indicator

Chess Companion Block Indicator

### Application Layers

### Working

- Connect with software serial for move suggestions
- Turn on leds when get a message for LEDs on
- Sound buzzer in different ways so that different events (Check, Game End)
- Turn off leds when get a message for LEDs off

### Sounds for buzzer
- for check three sound with 500ms gap
- for checkmate countinuous sound for 3 seconds

### checkmark before uploading the code.

- [] set const variable in main.cpp

sample input for serial monitor
`blocks h1h2h3a2d8f8g7 CHECK
blocks h1h2h3a2d8f8g7 END`