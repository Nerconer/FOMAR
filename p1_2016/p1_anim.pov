/* 
    Roda_dentada
*/
//
// Includes 
//
#include "colors"
#include "textures"
//
/*{{{ Definicio de l'objecte */ 
//
#declare Nabe=
   difference{cylinder{<0,-0.8,0>, <0,0.8,0>, 2}
              cylinder{<0,-1,0>, <0,1,0>, 1}
              torus{2, 0.3 translate 0.8*y}
              torus{2, 0.3 translate -0.8*y}}

#declare Speiche=
  union{box{<-0.5,-0.5,1.1>, <0.5,0.5,6>}
        difference{box{<-1.5,-0.5,6>, <1.5,0.5,7>}
                   cylinder{<-1.5,-1,6>,<-1.5,1,6>,1}
                   cylinder{<1.5,-1,6>,<1.5,1,6>,1} }}

#declare Ring=
   difference{cylinder{<0,-0.8,0>, <0,0.8,0>, 8}
              cylinder{<0,-1,0>, <0,1,0>, 7}
              torus{7, 0.3 translate 0.8*y}
              torus{7, 0.3 translate -0.8*y}}


#declare Zahn=
   difference{box{<-1.2,-0.8,0>, <1.2,0.8,1.3>}
              box{<-1,-2,-1>, <0,2,2> rotate 15*y translate -1*x}
              box{<0,-2,-1>, <1,2,2> rotate -15*y translate 1*x}}

#declare Roda_dentada=
   union{object{Nabe}
         #declare Winkel=90;
         #while (Winkel < 360)
                object{Speiche rotate Winkel*y}
                #declare Winkel=Winkel+360;
         #end
         object{Ring}
         #declare Winkel=0;
         #while (Winkel < 360)
                object{Zahn translate 7.8*z rotate (Winkel+10)*y}
                #declare Winkel=Winkel+20;
         #end
         texture{Copper_Metal}
         scale <13,13,13>  }

/*}}}*/
/*{{{ Definicio de sistema de referencia*/
#declare SRef=
   union{
         cylinder{<0, 0, 0>, <150, 0, 0>, 2 texture { pigment { color Red   } } }
         cylinder{<0, 0, 0>, <0, 140, 0>, 2 texture { pigment { color Green } } }
         cylinder{<0, 0, 0>, <0, 0, 150>, 2 texture { pigment { color Blue  } } }
        }

/*}}}*/
/*{{{ Definicio de sistema de referencia objectiu */
#declare SRob=
   union{
         cylinder{<0, 0, 0>, <150, 0, 0>, 1.99 texture { pigment { color 0.2   } } }
         cylinder{<0, 0, 0>, <0, 140, 0>, 1.99 texture { pigment { color 0.2   } } }
         cylinder{<0, 0, 0>, <0, 0, 150>, 1.99 texture { pigment { color 0.2   } } }
        }

/*}}}*/

// camera i llums
//
camera{ right -4/3*x 
        location <2000,2200,3300> 
        angle 57*600/4000
        look_at <0,0,0>}

light_source{ <100,200,200>
              color White}
light_source{ <-200,200,200>
              color White}
light_source{ <0,200,-400>
              color White}

#fopen Rij "rijxcolumnes" read
#read (Rij,r11,r21,r31,r12,r22,r32,r13,r23,r33)

#fopen Fis "fisef.out" read
#read (Fis,f1z,f1y,f1x)

// Escena
//


object {SRob matrix < r11,r21,r31,r12,r22,r32,r13,r23,r33, 0.0, 0.0, 0.0 > }

// 


//#declare Factor=sin(pi*clock)*sin(pi*clock);
#declare Factor=clock;

object{Roda_dentada rotate Factor*f1x*x rotate Factor*f1y*y rotate Factor*f1z*z}

object {SRef rotate Factor*f1x*x rotate Factor*f1y*y rotate Factor*f1z*z}



