.MODEL SMALL
.CODE
ORG 100H
JMP MULAI

;VARIABEL
nama    DB 0dh,0ah,0ah, "Masukan nama anda : ", '$'
id      DB 0dh,0ah, "Masukan ID anda : " , '$'
psn1    DB "Program Toko Buah" ,0dh,0ah, "------------------",'$'
psn2    DB 0dh,0ah,0dh,0ah, "Selamat datang di Toko buah ", '$'
psn3    DB 0dh,0ah,"==============================="
        DB 0dh,0ah, "|      Item yang tersedia :     |",0dh,0ah
        DB "|==============================|", 0dh,0ah
        DB "|NO|  Nama Item  |    Harga    |", 0dh,0ah 
        DB "|__|_ ___________|_____________|", 0dh,0ah
        DB "|1 | Pisang      | 18.000/kg   |", 0dh,0ah
        DB "|2 | Semangka    | 10.000/kg   |", 0dh,0ah
        DB "|3 | ApelMerah   | 30.000/kg   |", 0dh,0ah
        DB "|4 | Kiwi        | 63.000/kg   |", 0dh,0ah
        DB "|5 | Leci        | 154.000/kg  |", 0dh,0ah
        DB "|6 | AnggurMerah | 280.800/dus |", 0dh,0ah
        DB "|7 | Nanas       | 10.000/buah |", 0dh,0ah
        DB "|8 | Mangga      | 27.000/kg   |", 0dh,0ah
        DB "|9 | Alpukat     | 35.000/kg   |", 0dh,0ah
        DB "|10| Buah Naga   | 38.000/kg   |", 0dh,0ah
        DB "|11| Manggis     | 25.000/kg   |", 0dh,0ah
        DB "|12| Stroberi    | 20.000/pack |", 0dh,0ah 
        DB "|13| Jeruk       | 180.000/dus |", 0dh,0ah
        DB "|14| Melon       | 14.000/kg   |", 0dh,0ah
        DB "|15| Durian      | 15.000/kg   |", 0dh,0ah
        DB "|16| Nangka      | 7.400/kg    |", 0dh,0ah
        DB "|17| Pir         | 324.000/dus |", 0dh,0ah
        DB "|18| Plum        | 115.800/dus |", 0dh,0ah
        DB "|19| Rambutan    | 8.000/ikat  |", 0dh,0ah
        DB "|20| Salak       | 15.000/kg   |", 0dh,0ah
        DB "|21| Sirsak      | 18.000/kg   |", 0dh,0ah
        DB "|22| Delima      | 180.000/dus |", 0dh,0ah
        DB "|23| AnggurHijau | 320.000/dus |", 0dh,0ah
        DB "|24| Apel Hijau  | 32.000/kg   |", 0dh,0ah
        DB "================================", 0dh,0ah
        DB 0dh,0ah, 'Buah yang ingin dipilih : $' 
text    DB 0dh,0ah,  "Anda memilih item tersebut ", '$' 
msg1    DB 0dh,0ah,0dh,0ah,"semoga harimu meneyenangkan", '$'


tampung_nama    DB 30, ?, 30 dup(?)
tampung_id      DB 30, ?, 30 dup(?)

MULAI:
LEA DX,psn1
MOV AH,9
INT 21H

LEA DX,nama
MOV AH,9
INT 21H 

MOV AH,0AH
LEA DX,tampung_nama
INT 21H 
PUSH DX

LEA DX,ID
MOV AH,9
INT 21H 

MOV AH,0AH
LEA DX,tampung_ID
INT 21H 
PUSH DX

LEA DX,psn2
MOV AH,9
INT 21H

MULAI2:
LEA DX,psn3
MOV AH,9
INT 21H


Process:
MOV AH, 01
INT 21H 
    

Akhir:
   LEA DX,text
   MOV AH,9
   INT 21H

   
   LEA DX,msg1
   MOV AH,9
   INT 21H
   INT 20H 
   
   
   
EXIT:
RET                                 
    
