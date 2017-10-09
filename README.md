# Dog collar protocol

We've analysed a protocol of a pet collar we've bought from [Aliexpress](https://de.aliexpress.com/item/Rechargeable-Electric-Dog-Collar-300M-Remote-Dog-Training-Collar-Free-Shipping-Electric-Shock-And-Vibration-Collar/32441164095.html?spm=a2g0s.9042311.0.0.eaFVsL).
This was done with a cheap protocol analyser also bought from [Aliexpress](https://de.aliexpress.com/item/1set-New-Arrival-USB-Logic-Analyze-24M-8CH-MCU-ARM-FPGA-DSP-debug-tool/1963100593.html?spm=a2g0s.9042311.0.0.SQuyQZ).

# The story behind
We're a commune of students. All of us are studying computer science at a univerity of applied science.
A friend of us can be really annoying when he's drunk. Someday he came to our flat at 3am and screamed.
So we've decided to make a little experiment with him. He can only access our flat if he's wearing this collar. Every time he's too loud, he gets a shock.

### First step
Sooo, how we did this?

We disassembled the remote of the collar and connected the logic analyser to the ground and the corresponding signal pin of the antenna.
Every time you send a signal you can record it in parallel, for example with this compatible software from [Saleae](https://www.saleae.com/de/downloads). Now you can see the rising and falling edges with the specific timings. Unfortunately the analyser isn't that good so you can't just get the decoded protocol. So we decided to export it and do it the dirty way.

### Second step analysing
We used a WeMos D1 mini to access the pet collar via the browser (in progresss) and attached a simple 433MHz sender. In order to trigger a shock, a simple button was used for testing purposes (code).
With the software described above you can export your recording to a csv file. In this file you can see the timings of the rising and falling edges the controller sends to the pet collar. The corresponding excel file you can find in this repo, too. If you just paste the recorded sequence in the excel-sheet you get the arduino code to replay the redordings. This would theoretically suffice, but since the collar can shock and vibrate and also supports 100 adjustable steps, this would be too much overhead to record each sequence.

We've recorded some packages and compared them with each other and searched for similarities and differences (highlighted in the excel sheet). We found out that the strength is only decoded binary. Different headers are used in the protocol to distinguish between shock and vibration. 

