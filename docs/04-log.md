2026-08-21 Project initialization
Basic project hierarchy was created, there is a lot still to be done but I'm on the right way.
At this point I added basic information about parts im using in prototype, created project in VScodium Next task is to add tasks (ironic)

2026-08-23 creation of tasks
Created basic tasks and started making setup tasks. After that completed writing pinouts

2026-08-29 Automatic pushing script
I Created script for auto pushing to git after im done for a day

2026-08-30 Initial Testing Env
Today I created basic testing environment for testing parts of code that dont need microcontroller to work


2026-09-01 Finding Addresses
I fixed remaining problems with IDE and after that run I2C scannner to find all addresses of my sensor, started establishing communication with BH1750

2026-09-09 Buffering
Basic Ring buffer was written, its functionality tested. Currently data can only be added to it but not read. Real problem is thinking out solution of how to read data

2026-09-15 Finished Buffer and starting of dashboard site
With ring buffer i decided for moving average data acqusition. It still may change based on methods use for ESP32. My main concern is power usage. Also i started setting up Dashboard site for the project, I settled with Thingsboard
