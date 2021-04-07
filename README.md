# mbed_exam1

##For slew rate = 1/8:

![image](https://user-images.githubusercontent.com/72603727/113842872-b7076a00-97c5-11eb-955d-5499c663b485.png)
![image](https://user-images.githubusercontent.com/72603727/113842902-bc64b480-97c5-11eb-8f42-be445e1529b4.png)
![image](https://user-images.githubusercontent.com/72603727/113842915-bf5fa500-97c5-11eb-80c7-2d617bedd637.png)

##For slew rate = 1/4:

![image](https://user-images.githubusercontent.com/72603727/113842976-c981a380-97c5-11eb-8d41-36e32a4ea97e.png)
![image](https://user-images.githubusercontent.com/72603727/113844584-38133100-97c7-11eb-8b2d-6c862b8a55ef.png)
![image](https://user-images.githubusercontent.com/72603727/113843008-d0101b00-97c5-11eb-97d1-eaf0d95d3da7.png)

##For slew rate = 1/2:

![image](https://user-images.githubusercontent.com/72603727/113843058-dc947380-97c5-11eb-95fd-9c06536a09e2.png)
![image](https://user-images.githubusercontent.com/72603727/113843061-de5e3700-97c5-11eb-96f7-2480c0b92f60.png)
![image](https://user-images.githubusercontent.com/72603727/113843073-e0c09100-97c5-11eb-8e2c-dc4dba9b25fd.png)

##For slew rate = 1:

![image](https://user-images.githubusercontent.com/72603727/113843141-ed44e980-97c5-11eb-8f25-40871b89cd7a.png)
![image](https://user-images.githubusercontent.com/72603727/113843161-efa74380-97c5-11eb-8b57-b62122b26e29.png)
![image](https://user-images.githubusercontent.com/72603727/113843181-f2a23400-97c5-11eb-9ae3-53561a3b0a8f.png)

我的main.cpp檔裡面，首先是先選擇slew rate，我用和作業2相同的手法，以1/8為初始值開始往上增加，按一次UP鍵slew rate乘以2直到1為止，按一次DOWN鍵slew rate除以2直到1/8為止。
按下select鍵之後跳出選擇slew rate的迴圈，並且進入產生波型的迴圈。產生波型的同時，我用thread去同步的取樣(共取500次)，測試出來的取樣頻率大約是500Hz。


##接線

![image](https://user-images.githubusercontent.com/72603727/113845038-ab1ca780-97c7-11eb-94bf-59e72f042618.png)
![image](https://user-images.githubusercontent.com/72603727/113845066-b243b580-97c7-11eb-855e-51e5347793bf.png)
![image](https://user-images.githubusercontent.com/72603727/113845102-bb348700-97c7-11eb-8b31-2290db8a97c9.png)
