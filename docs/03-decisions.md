Im going to measure

| Object               | Unit                                           |
| -------------------- | ---------------------------------------------- |
| Moisture             | percentage                                     |
| Battery level        | percentage                                     |
| Temperature          | Celcius / kelvin                               |
| Atmospheric pressure | hPa                                            |
| Light                | Lux / Percentage (not sure about this one yet) |
buffer logic
1. Every **15 mins** gather 64 values from sensors and average them out (to that maybe add history from last data collection)
2. Every **4 snaphots** send data from json to server (this should take around **1h**)