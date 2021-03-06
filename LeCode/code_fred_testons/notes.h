/*********************************************************************
        * Absolument toutes les notes d'un piano classique,
        *   sans oublier la définition de pleeeeeiiiiiin
        *               d'autres variables !
*********************************************************************/



#define NOTE_A0 27
#define NOTE_AS0 29
#define NOTE_B0  31


/*---------------------------------------------------------*/

/*    début octave n°1    */
#define NOTE_C1  33   //première note jouable -> Do0
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52   //Première note qui nous est AUDIBLE !
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
/*     fin octave n°1     */

/*    début octave n°2    */
#define NOTE_C2  65    //Do1
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
/*     fin octave n°2     */

/*    début octave n°3    */
#define NOTE_C3  131    //Do2
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
/*     fin octave n°3     */

/*    début octave n°4    */
#define NOTE_C4  262    //Do3
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440    //La3
#define NOTE_AS4 466
#define NOTE_B4  494
/*     fin octave n°4     */

/*    début octave n°5    */
#define NOTE_C5  523    //Do4
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
/*     fin octave n°5     */

/*    début octave n°6    */
#define NOTE_C6  1047    //Do5
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
/*     fin octave n°6     */

/*    début octave n°7    */
#define NOTE_C7  2093    //Do6
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
/*     fin octave n°7     */

#define NOTE_C8  4186   //dernière note jouable -> Do7

/*---------------------------------------------------------*/

#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST     0







/*********************************************************************
 *         Définissons maintenant le reste des variables
 *             et trions ce qui a été fait ci-dessus.
*********************************************************************/



int notes[85] = {
  NOTE_C1,
  NOTE_CS1,
  NOTE_D1,
  NOTE_DS1,
  NOTE_E1,
  NOTE_F1,
  NOTE_FS1,
  NOTE_G1,
  NOTE_GS1,
  NOTE_A1,
  NOTE_AS1,
  NOTE_B1,
  NOTE_C2,
  NOTE_CS2,
  NOTE_D2,
  NOTE_DS2,
  NOTE_E2,
  NOTE_F2,
  NOTE_FS2,
  NOTE_G2,
  NOTE_GS2,
  NOTE_A2,
  NOTE_AS2,
  NOTE_B2,
  NOTE_C3,
  NOTE_CS3,
  NOTE_D3,
  NOTE_DS3,
  NOTE_E3,
  NOTE_F3,
  NOTE_FS3,
  NOTE_G3,
  NOTE_GS3,
  NOTE_A3,
  NOTE_AS3,
  NOTE_B3,
  NOTE_C4,
  NOTE_CS4,
  NOTE_D4,
  NOTE_DS4,
  NOTE_E4,
  NOTE_F4,
  NOTE_FS4,
  NOTE_G4,
  NOTE_GS4,
  NOTE_A4,
  NOTE_AS4,
  NOTE_B4,
  NOTE_C5,
  NOTE_CS5,
  NOTE_D5,
  NOTE_DS5,
  NOTE_E5,
  NOTE_F5,
  NOTE_FS5,
  NOTE_G5,
  NOTE_GS5,
  NOTE_A5,
  NOTE_AS5,
  NOTE_B5,
  NOTE_C6,
  NOTE_CS6,
  NOTE_D6,
  NOTE_DS6,
  NOTE_E6,
  NOTE_F6,
  NOTE_FS6,
  NOTE_G6,
  NOTE_GS6,
  NOTE_A6,
  NOTE_AS6,
  NOTE_B6,
  NOTE_C7,
  NOTE_CS7,
  NOTE_D7,
  NOTE_DS7,
  NOTE_E7,
  NOTE_F7,
  NOTE_FS7,
  NOTE_G7,
  NOTE_GS7,
  NOTE_A7,
  NOTE_AS7,
  NOTE_B7,
  NOTE_C8
};



int the_set[13] = {};
//notre 'set' de 13 différentes notes successives


int current_set_number = 0;
//numéro de notre 'set', allant de 2 à 7 inclus


int pitchbend_variations_set[13] = {};
//liste contenant la plage de variation de chacunes
//des 13 notes de the_set[] pour l'effet pitchbend


const int where_bend = 0;
int an0;

int actual_frequencies[13] = {};
//liste contenant la note à jouer pour chaque
//touche en fonction de an0


/* 
the_set[], current_set_number et pitchbend_variations_set[]
seront modifiés uniquement lorsqu'il y aura un changement de set,
permettant ainsi de limiter les calculs.
En revanche, actual_frequencies[] sera modifié à chaque fois
que l'on modifiera la valeur renvoyée par le potentiomètre
(qui sera an0).
*/



const int mini_l_pad[28] = {
  NOTE_C4, NOTE_DS4, NOTE_E4, NOTE_G4,
  NOTE_D4, NOTE_F4, NOTE_FS4, NOTE_A4,
  NOTE_E4, NOTE_G4, NOTE_GS4, NOTE_B4,
  NOTE_F4, NOTE_GS4, NOTE_A4, NOTE_C5,
  NOTE_G4, NOTE_AS4, NOTE_B4, NOTE_D5,
  NOTE_A4, NOTE_C5, NOTE_CS5, NOTE_E5,
  NOTE_B4, NOTE_D5, NOTE_DS5, NOTE_FS5
};

/*
mini_pad[] est le set de note pour
le piano secondaire gauche.
*/


int left_index[3] = {0, 2, 3};

bool minl = LOW;
bool majl = HIGH;

/*
left_index[] est la liste d'indices qui correspondent
aux trois notes de mini_pad[] qui seront jouées par
le piano secondaire gauche. left_index[] sera mis
à jour à chaque fois que l'on presse une touche
différente et/ou que l'on passe d'un accord mineur
à majeur et vice versa (sur le piano gauche).
*/



char charblu = '\0';

/*
charblu sera utile pour savoir quel caractère a été
envoyé par le téléphone via Bluetooth.
*/



const int where_time = 1;
int an1;
int delta_temps;
int diviseur;

/*
delta_temps sera modifié à chaque fois que l'on modifiera 
la valeur renvoyée par le potentiomètre (qui sera an1).
*/



int mode = 0;
bool mode_is_changing = LOW;

/*
mode permet de savoir quel effet bluetooth est activé.
Il vaut 0 quand il n'y en a aucun d'actuellement activé.
mode_is_changing permettra d'arrêter la boucle de code
en cours d'exécution et de la recommencer
*/


unsigned long last_time = 0;
unsigned long current_time = 0;
bool metronome = LOW;
unsigned int metrovalle = 1000;   //soit une seconde (BPM valant 60 par défaut)
bool led_tempo_state = LOW;
int tournement_total = 0;
char ancienne_image = '\0';

/*
last_time et current_time (toujours positives)
serviront pour la led "métronome". metrovalle[] lui
"donnera" sa cadence et led_tempo_state son "état".
*/


//----Couleurs----
int bleu_lavande[3] = {145, 145, 255};      //#9191FF
int rose_bonbon[3] = {255, 104, 169};       //#FF68A9

int golden[3] = {255, 215, 0};              //#FFD700
int tomato[3] = {255, 99, 71};              //#FF6347
int deep_sky_blue[3] = {0, 191, 255};       //#00BFFF

int dark_violet[3] = {148, 0, 211};         //#9400D3
//----------------



int special_r_gaps[20];                         //pour le mode arpège
int special_r_set[20];                          //pour le mode arpège
int special_actual_r_frequencies[20];           //pour le mode arpège
int special_right_index[3];                     //pour le mode arpège



int perissando_gaps_live[13];                   //pour le mode périssando
int actual_peri_nb = 0;                         //pour le mode périssando
int total_peri_gaps = 240;                      //pour le mode périssando
int one_peri_gap = 2*PI / total_peri_gaps;      //pour le mode périssando
int perissando_sub_div = 3;                     //pour le mode périssando
int perissevolution = 0;                        //pour le mode périssando



#include "aled.h"
