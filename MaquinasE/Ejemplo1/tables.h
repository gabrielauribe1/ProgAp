/************************************************************************
 *									*
 * Archivo:	tables.h						*
 * Descripcion: Tablas para la maquina de estados y funciones externas	*
 *		Aqui se definen todos las tablas que se utilizan	*
 *		en el programa						*
 *									*
 ************************************************************************/

/*************** ARCHIVOS DE INCLUSION ***************/ 
#include "local.h"
#include <stdio.h>


/*************** FUNCIONES EXTERNAS *********************
 * En esta seccion se declaran los encabezados de 	*
 * todas las funciones que se utilizan en las     	*
 * tablas del programa. Todas las funciones deben 	*
 * ser de tipo entero y no deben recibir parametros	*
 ********************************************************/ 
extern int EstadoA(void);
extern int EstadoB(void);
extern int Estadoaa(void);
extern int Estadob(void);
extern int nul(void);

/******************** TABLAS ********************
 * En esta seccion se declaran las tablas	*
 * que se van a usar en el programa		*
 ************************************************/ 
 
/*************** TABLA DE ACCION ***************/  
ACTION_TAB action_table[]={
/*etype     accion     bandera   sigEdo. */    
    { EntradaA,  EstadoA,  	-1,	EdoA},
    { EntradaB,  EstadoB,	-1,	EdoB},
    { -1, nul,	        -1,	Inicio},
    { Entradaa,  Estadoaa,	-1,	Inicio},
    { -1, nul,  	-1,	EdoA},
    { Entradab,  Estadob ,	-1,	EdoB},
    { -1, nul,  	-1,	Inicio},  
};

/*************** TABLA AUXILIAR ***************/  
    AUX_TAB aux_table[]={        
/*    accion       bandera           sigEdo */
    { nul,           0,                 0},
};

/*************** TABLA DE ESTADOS ***************/  
STATE_TAB state_table[]={
   /*estado      inicio   fin */
    {Inicio,      0,      2},
    {EdoA,        3,      4},
    {EdoB,        5,      6},
};


    
        

        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
    
        
