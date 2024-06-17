#include <stdio.h>
#include <time.h> 
#include <math.h>
//Estructuras
struct Ubicacion{
    float lat, lon;
}; 
struct TiempoActual{
    int aC,mC,dC,hC,minC;
};
struct Tiempo{
    int a,m,d,a1,m1,d1;
};
struct DeclinacionSolar{
    double dsG, dsR;
};
struct EcuacionTiempo{
    double etG, etR;
};
struct ZonaHoraria{
    int lonEstand, zH;
};
struct HoraSolarVerdadera{
    double TsD; 
    int TsH, TsM;
};
struct AlturaSol{
    double HG, HR, asG, asR;
};
struct Azimut{
    double aziG, aziR;
};
//Funciones y Procedimientos
void Pgar(double *variable){
    double Pi=3.1415926535;
    *variable=((*variable*Pi)/180.0);
}
void Prag(double *variable){
    double Pi=3.1415926535;
    *variable=((*variable*180)/Pi);
}
void PtiempoActual(int *aC,int *mC, int *dC, int *hC, int *minC){
    time_t t;
    time(&t);
    struct tm *tm_info = localtime(&t);
    *aC = tm_info->tm_year + 1900; //Numero de aÑos desde 1900
    *mC = tm_info->tm_mon + 1;     //Numero de meses desde (0-11)
    *dC = tm_info->tm_mday;
    *hC = tm_info->tm_hour;
    *minC = tm_info->tm_min;
}
void PubicacionDireccion(float lat, float lon){
    if (lat>0){
        printf("Valor de latitud de su zona geografica\n%f N\n", lat);
    } else{
        printf("Valor de latitud de su zona geografica\n%f S\n", (-1*lat));
    }
    if (lon>0){
        printf("Valor de longitud de su zona geografica\n%f E\n", lon);
    } else{
        printf("Valor de longitud de su zona geografica\n%f O\n", (-1*lon));
    }
}
void Ptiempo(int *a, int aC, int *m, int mC, int *d, int dC, int *a1, int *m1, int *d1){
    *d=1; //??????
    *m=1;
    printf("el valor de dias de este mes dentro de void es: %d\n", dC);
    *a1=aC-*a;
    *m1=mC-*m;
    for(*m=1; *m<mC; *m=*m+1){
        if (*m==1||*m==3||*m==5||*m==7||*m==8||*m==10||*m==12){
            dC+=31;
            printf("en el mes %d dias 31 cambio a %d\n", *m, dC);
        } else if(*m==2){ //Año bisiesto
            if(aC%4==0){
                dC+=29;
                printf("AB en el mes %d 29 dias cambio a %d\n", *m, dC);
            }else{
                dC+=28;
                printf("ANB en el mes %d 28 dias cambio a %d\n", *m, dC);
            }
        } else if(*m==4||*m==6||*m==9||*m==11){
            dC+=30; //Sumar 30 dias a los meses 4,6,9,11
            printf("en el mes %d dias 30 cambio a %d\n", *m, dC);
        }
    }
    *d1=dC; 
}
void PdeclinancionSolar(int a, int d1, double *decSolar, double *decSolarR){
    double ec;
    if(a%4==0){
        ec=360.0/366.0*(d1+10);
        printf("Valor de M1 es: %f\n", ec);
    } else{
        ec=360.0/365.0*(d1+10);
    }
    Pgar(&ec);
    *decSolar=(-23.44)*cos(ec);
    *decSolarR=*decSolar;
    Pgar(&*decSolarR);
}
void PecuacionTiempo(int a, int d1, double *ecTiempo){
    double B;
    if(a%4==0){
        B=360.0/366.0*(d1-81);
    } else{
        B=360.0/365.0*(d1-81);
    }
    Pgar(&B);
    *ecTiempo=9.87*(sin(2*B))-(7.53*cos(B))-(1.5*sin(B));
}
void PzonaHoraria(int lonEntero, int *lonEs, int *zH){
    if (lonEntero%15==0){
        *lonEs=lonEntero;
        *zH=lonEntero/15;
    }else{
        if (lonEntero>0){
            while(lonEntero%15!=0){
                lonEntero--;
            }
            *lonEs=lonEntero;
            *zH=lonEntero/15;
        } else{
            while(lonEntero%15!=0){
                lonEntero++;
            }
            *lonEs=lonEntero;
            *zH=lonEntero/15;
        }
    }
}
void PhoraSolarVerdadera(int hC, int minC, float lon, int lonEs, double EcTiempo, double *TsD, int *TsH, int *TsM){
    double hdec=hC+(minC/60.0);
    printf("Hora en decimales: %f\n", hdec);
    *TsD=hdec+((4*(lon-lonEs)+EcTiempo)/60.0);
    printf("Hora solar en decimales: %F\n", *TsD);
    *TsH=*TsD;
    printf("Hora solar en horas: %d\n", *TsH);
    *TsM= round((*TsD-*TsH)*60);
    printf("Hora solar en minutos: %d\n", *TsM);
}
void PalturaSol(double TsD, double *HG, double *HR, double lat , double decSolar, double *asR, double *asG){
    *HG=15*(TsD-12);
    *HR=*HG;
    Pgar(&*HR);
    Pgar(&lat);
    *asR=asin((sin(decSolar)*sin(lat))+(cos(decSolar)*cos(lat)*cos(*HR)));
    *asG=*asR;
    Prag(&*asG);
}
void Pazimut(double decSolar, double asR, double lat, double HR ,double *aziR, double *aziG){
    double Pi=3.1415926535;
    Pgar(&lat);
    *aziR=acos((sin(decSolar)-sin(asR)*sin(lat))/(cos(asR)*cos(lat)));
    if (HR>0){
        *aziR=(2*Pi)-*aziR;
        printf("El valor del azimut cambio");
    }
    *aziG=*aziR;
    Prag(&*aziG);
}
//Funcion principal
int main(){
    //Fecha y Hora
    struct TiempoActual tmpa; //  <-------- ESTRUCTURA
    PtiempoActual((&tmpa.aC),(&tmpa.mC),(&tmpa.dC),(&tmpa.hC),(&tmpa.minC)); //Llamo a la funcion
    printf("Fecha: %d/%d/%d , Hora: %d:%d\n", (tmpa.dC),(tmpa.mC),(tmpa.aC),(tmpa.hC),(tmpa.minC)); //Escribo los valores que me devuelve la funcion
    //Coordenadas
    struct Ubicacion coordenada; //  <-------- ESTRUCTURA
    printf("Bienvenido al programa para calcular la direccion y altura del sol\nSe requiere de tus coordenadas para realizar el calculo\n");
    printf("Ingresa la latitud\n");
    scanf("%f", &coordenada.lat);
    if (coordenada.lat==0){
        coordenada.lat=-3.99313; //Eliminar esta condicion //O agregar error???
    }
    printf("Ingresa la longitud\n");
    scanf ("%f", &coordenada.lon);
    if (coordenada.lon==0){ 
        coordenada.lon=-79.20422; //Eliminar esta condicion   //Operadores Ternarios????
    }
    PubicacionDireccion((coordenada.lat),(coordenada.lon));
    printf("Una vez cambiado NSEO las cooredenas son: %f y %F\n", coordenada.lat, coordenada.lon); //Quitar linea????
    //Diias transcurridos
    struct Tiempo tmp; //  <-------- Estructura
    tmp.a=tmpa.aC; //Asignar //Se puede borrar o no??
    printf("el valor de dias de este mes es: %d\n", tmpa.dC);
    Ptiempo((&tmp.a),(tmpa.aC),(&tmp.m),(tmpa.mC),(&tmp.d),(tmpa.dC),(&tmp.a1),(&tmp.m1),(&tmp.d1)); //Llamo a la funcion
    printf("Fechas hasta ahora: %d anios, %d meses, %d dias\n", (tmp.a1),(tmp.m1),(tmp.d1)); //Escribo los valores que me devuelve la funcion
    //Primera Formula: DECLINACION SOLAR
    //Variables utilizadas: dias totales del año, dias que han transcurrido desde el inicio del año 
    struct DeclinacionSolar decSolar; //  <-------- Estructura
    PdeclinancionSolar((tmp.a),(tmp.d1),(&decSolar.dsG),(&decSolar.dsR)); //Llamo a la funcion
    printf("Valor de la declinacion solar %f en grados\n", decSolar.dsG); //Escribo los valores que me devuelve la funcion
    //Segunda formula: Ecuacion del Tiempo
	//Variables utilizdas; dias totales del año, dias que han transcurrido desde el inicio del año .
    struct EcuacionTiempo ecTiempo; //  <-------- Estructura
    PecuacionTiempo((tmp.a),(tmp.d1),(&ecTiempo.etR)); //Llamo a la funcion
    printf("Valor de la ecuacion del tiempo %f en radianes\n", ecTiempo.etR); //Escribo los valores que me devuelve la funcion
    //Longitud y Zona Horaria
    struct ZonaHoraria zhoraria; //  <-------- Estructura
    PzonaHoraria((coordenada.lon),(&zhoraria.lonEstand),(&zhoraria.zH)); //Llamo a la funcion
    printf("Valor de la longitud estandar: %d\nTu zona horaria es: %d\n", zhoraria.lonEstand, zhoraria.zH); //Escribo los valores que me devuelve la funcion
    //Tercera formula: Hora solar verdadera
	//Variables utilizadas: horas y minutos actuales,zona horaria, longitud , longitud estandar, ecuacion del tiempo.
    struct HoraSolarVerdadera TiempoSolar;
    PhoraSolarVerdadera((tmpa.hC),(tmpa.minC),(coordenada.lon),(zhoraria.lonEstand),(ecTiempo.etR),(&TiempoSolar.TsD),(&TiempoSolar.TsH),(&TiempoSolar.TsM));
    printf("Valor de la Hora solar:\n%f en decimales\n%d en horas y %d minutos\n", (TiempoSolar.TsD),(TiempoSolar.TsH),(TiempoSolar.TsM));
    //Cuarta formula: Altura del sol
	//Variables utilizadas: Declinacion solar, latitud, hora solar, altura del sol sobre el horizonte (H)
    struct AlturaSol altSol; //  <-------- Estructura
    PalturaSol((TiempoSolar.TsD),(&altSol.HG),(&altSol.HR),(coordenada.lat),(decSolar.dsR),(&altSol.asR),(&altSol.asG));
    printf("Valor de H: %f en radianes\nValor de la altura solar:\n%f en radianes\n%f en grados\n", (altSol.HR),(altSol.asR),(altSol.asG));
    //Quinta formula: Azimut
	//Variables utilizadas: 
    struct Azimut azi; //  <-------- Estructura
    Pazimut((decSolar.dsR),(altSol.asR),(coordenada.lat),(altSol.HR),(&azi.aziR),(&azi.aziG)); //Llamo a la funcion
    printf("El valor de Azimut: %f en radianes\nEl valor de azimut: %f en grados\n", (azi.aziR),(azi.aziG));
    return 0;
}