void setup()
{
    Serial.begin(9600);
}
 
void loop()
{
   convert(analogRead(A0));
}

void convert(int data){

    int bin[10];
    int index_bin = 0;
    int i = 512;
    while (i > 0){
        if (i > data){
            i = i / 2;
            bin[index_bin] = 0;
        }
        else{
            data = data - i;
            i = i / 2;
            bin[index_bin] = 1;
        }
        index_bin++;
    }
    for(int i = 0; i < 10 ; i ++){
       digitalWrite(i+2,bin[i]);
       Serial.print(bin[i]);
    }
    Serial.println();
   
}

