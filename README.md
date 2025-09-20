### Config:

Konfiguracja znajduje się w pliku config.h
Ważne parametry:
- #define FRONT_LINE_SENSOR 0
- #define BACK_LINE_SENSOR 0

należy ustawić 1 lub 0 w zależności od tego czy dany czujnik jest podłączony

- int lineColor = 1;

ustawia kolor linii (1 - czarna, 0 - biała)

Przypisanie pinów znajduje się w pliku main.cpp:

### Platformio:

Build

```sh
pio run
```

Upload

```sh
pio run --target upload
```

Monitor

```sh
pio device monitor
```

Upload and Monitor

```sh
pio run --target upload --target monitor
```

### Śruby:

| Rozmiar | Ilość | Elementy              |
| ------- | ----- | --------------------- |
| 3x8     | 4     | 1,4                   |
| 2.5x6   | 4     | 4,arduino uno         |
| 2x16    | 3     | 2,3                   |
| 3x30    | 4     | 1,motor               |
| 4x12    | 2     | 1,tylnie kółko        |
| 2x12    | 2-4   | 1,line finder         |
| 4x10    | 2     | 1,5                   |
| 3x16    | 2     | 5,6,8,distance sensor |
| 4x12    | 2     | 1,7                   |
| 3x10    | 2     | 7,8,distance sensor   |
| 3x16    | 4-10  | 1,2                   |
