#include <stdio.h>
#include <string.h>

/*struct Dato {
    int num1 ;
    int telefono;

} dato1;
struct Persona{
	char nombre[20];
	struct Dato datos_persona;
}personas;
*/
typedef struct{
    char nombre_de_materia[30];
    int cantidad_de_alumnos;
    int horario_de_inicio;
    char turno[10];
} materia;

struct Maestro{
    char nombre[30];
    int edad;
    materia datos_de_asignatura;
} maestros;

char cadena[50];
int i,largo,tam_cadena,cont;		//Se declaran variables para
int tamanoCadena(char cadena[]);
void desplegar (char * arreglo, int a);

int main()
{
    printf("Escriba el nombre de la Universidad\n");          //--
    gets(cadena);											   //--
    tam_cadena = tamanoCadena(cadena);						    //--
    //--
    //printf("El largo de la cadena es : %i\n",tam_cadena); 	   //--
    //se obtiene el largo de la cadena							   //--
    //--
    //printf("Asignando memoria de manera dinamica... \n");			 //--
    char array[tam_cadena];											  //--
    char *arreglo= &array[0];										   //--
    arreglo = (int*)malloc(tam_cadena*sizeof(int*));					//--
    //--
    //printf("Copiando arreglo a memoria dinamica... \n");							//Obtener Nombre de la Universidad//
    for(i=0;i<tam_cadena;i++)											  //
    {																	//--
        *(arreglo + i)=cadena[i];									  //--
        //printf("%c",nombre[i]);									//--
    }															  //--
    //--
    //printf("Imprimiendo de memoria dinamica... \n");		  //--
    desplegar(arreglo,tam_cadena);							//--


    printf("\n\n\n");
    desplegar(arreglo,tam_cadena);
    printf("\nIngrese los datos de los maestros a continuacion...\n\n");


    char nombre_solicitado[50],nombre_materia_solicitado[50],turno_solicitado[2]; //Datos struct
    int edad_solicitada, cantidad_de_alumnos, horario_de_materia; //Datos struct
    char espacio_vacio[3] =" ";
    struct Maestro maestros[10][10];
    int numero_de_personas, numero_de_datos, i, j, count, numero_escaneado, numero_datos;
    //int array_dimension[3];
    printf("Digite el numero de maestros (max. 10) : ");
    scanf("%i",&numero_de_personas);

    int array_dimension[numero_de_personas];
    int *arreglo_dimension= &array_dimension[0];
    arreglo_dimension = (int*)malloc(numero_de_personas*sizeof(int*)); //creo arreglo 2d dinamico para obtener los datos exactos que se ingresaran
    int **arr = (int **)malloc(numero_de_personas * sizeof(int *));


    int contador_personas=1;
    for (i=0; i<numero_de_personas; i++)
    {
        printf("Digite el nombre del maestro %i\n",contador_personas);
        scanf("%s",nombre_solicitado);
        printf("Digite la edad del maestro\n");
        scanf("%i",&edad_solicitada);

        strcpy(maestros[i][0].nombre,nombre_solicitado); //se coloca el dato a el struct
        maestros[i][0].edad=edad_solicitada;				//se coloca el dato a el struct

        printf("Digite el numero de materias que imparte el maestro : ");
        scanf("%i",&numero_de_datos);
        array_dimension[i]=numero_de_datos;
        arr[i] = (int *)malloc(numero_de_datos * sizeof(int));
        count = 0;
        contador_personas++;

        for (j = 0; j < numero_de_datos; j++)
        {
            arr[i][j] = ++count;

            printf("%d ", arr[i][j]);
            printf("Escriba el nombre de la materia \n");
            scanf("%s",nombre_materia_solicitado);
            printf("Digite la cantidad de alumnos de la materia\n");
            scanf("%i",&cantidad_de_alumnos);
            printf("Digite el horario de inicio de la materia\n");
            scanf("%i",&horario_de_materia);
            printf("Digite el Turno \n");
            scanf("%s",turno_solicitado);

            strcpy(maestros[i][j].datos_de_asignatura.nombre_de_materia,nombre_materia_solicitado); //asigno a struct
            maestros[i][j].datos_de_asignatura.cantidad_de_alumnos=cantidad_de_alumnos;
            maestros[i][j].datos_de_asignatura.horario_de_inicio=horario_de_materia;
            strcpy(maestros[i][j].datos_de_asignatura.turno,turno_solicitado);

        }


        //agregar for i=0  for j=0
    }
    printf("\nLa cantidad extraida de datos de persona en orden es:");
    for(i=0;i<numero_de_personas;i++)
    {
        printf("%i ",array_dimension[i]); //imprime el Arreglo que extrae la cantidad de c
    }


    /*/printf("\nLos datos del struct son\n");
    for(i=0;i<numero_de_personas;i++)
    {

        printf("\nNombre : %s\n",maestros[i][0].nombre);
        printf("Edad : %i,\n", maestros[i][0].edad);


    //antes de la adicion funciona bien, no encontre la falla
      for(j=0;j<numero_datos;j++)
      {
          printf("Conglomerado de datos : %i \n",arr[i][j]);
          printf("Nombre de la materia : %s",maestros[i][j].datos_de_asignatura.nombre_de_materia);
        printf("Cantidad de alumnos : %i",maestros[i][j].datos_de_asignatura.cantidad_de_alumnos);
        printf("Horario de inicio : %i",maestros[i][j].datos_de_asignatura.horario_de_inicio);
        printf("Turno : %s\n",maestros[i][j].datos_de_asignatura.turno);
      }
    }*/

    desplegar(arreglo,tam_cadena);
    printf("\nSeleccione al Maestro:\n");
    for(i=0;i<numero_de_personas;i++)
    {
        printf(" %i |%10s|\n",i+1,maestros[i][0].nombre);
    }
    printf("\n");
    scanf("%i",&numero_escaneado);
    numero_escaneado-=1;
    numero_datos= array_dimension[numero_escaneado]; //le asigno el numero buscado al arra_dimension para obtener el numero de sus datos
    printf("Sus datos son:\n");
    printf("\n");

    printf("Nombre : %s\n",maestros[numero_escaneado][0].nombre);
    printf("Edad : %i,\n", maestros[numero_escaneado][0].edad);
    for(i=0;i<numero_datos;i++)
    {
        printf("\nMateria : %i \n",arr[numero_escaneado][i]);
        printf("Nombre de la materia : %s ",maestros[numero_escaneado][i].datos_de_asignatura.nombre_de_materia);
        printf("Cantidad de alumnos : %i ",maestros[numero_escaneado][i].datos_de_asignatura.cantidad_de_alumnos);
        printf("Horario de inicio : %i ",maestros[numero_escaneado][i].datos_de_asignatura.horario_de_inicio);
        printf("Turno : %s ",maestros[numero_escaneado][i].datos_de_asignatura.turno);
    }
    printf("\n");


    int menu;
    printf("\n\nSeleccione la opcion\n1.Seleccionar Maestro\n2.Imprimir Tabla\n3.Modificar No. Alumnos");
    scanf("%i",&menu);



    while(menu<4)
    {
        if(menu==1)
        {
            printf("\nSeleccione al Maestro:\n");
            for(i=0;i<numero_de_personas;i++)
            {
                printf(" %i |%10s|\n",i+1,maestros[i][0].nombre);
            }
            printf("\n");
            scanf("%i",&numero_escaneado);
            numero_escaneado-=1;
            numero_datos= array_dimension[numero_escaneado]; //le asigno el numero buscado al arra_dimension para obtener el numero de sus datos
            printf("Sus datos son:\n");
            printf("\n");

            printf("Nombre : %s\n",maestros[numero_escaneado][0].nombre);
            printf("Edad : %i,\n", maestros[numero_escaneado][0].edad);
            for(i=0;i<numero_datos;i++)
            {
                printf("\nMateria : %i \n",arr[numero_escaneado][i]);
                printf("Nombre de la materia : %s ",maestros[numero_escaneado][i].datos_de_asignatura.nombre_de_materia);
                printf("Cantidad de alumnos : %i ",maestros[numero_escaneado][i].datos_de_asignatura.cantidad_de_alumnos);
                printf("Horario de inicio : %i ",maestros[numero_escaneado][i].datos_de_asignatura.horario_de_inicio);
                printf("Turno : %s ",maestros[numero_escaneado][i].datos_de_asignatura.turno);
            }
            printf("\n");
        }

        if(menu==2)
        {
            //forma de tabla
            printf("Forma de Tabla\n");
            printf("|  Nombre  | Edad | Materia |No. Alumnos| Horario | Turno |",maestros[i][0].nombre,maestros[i][0].edad);
            for(i=0;i<numero_de_personas;i++)
            {

                printf("\n|%10s|%6i|",maestros[i][0].nombre,maestros[i][0].edad);




                for(j=0;j<numero_datos;j++)
                {
                    //printf("Conglomerado de datos : %i \n",arr[i][j]);
                    if(j<numero_datos-1)
                    {

                        printf("%9s|",maestros[i][j].datos_de_asignatura.nombre_de_materia);
                        printf("%11i|",maestros[i][j].datos_de_asignatura.cantidad_de_alumnos);
                        printf("%9i|",maestros[i][j].datos_de_asignatura.horario_de_inicio);
                        printf("%7s|",maestros[i][j].datos_de_asignatura.turno);
                        printf("\n|%10s|%6s|",espacio_vacio,espacio_vacio);
                    }
                    if(j==numero_datos-1) //elimina las dobles rallas
                    {
                        printf("%9s|",maestros[i][j].datos_de_asignatura.nombre_de_materia);
                        printf("%11i|",maestros[i][j].datos_de_asignatura.cantidad_de_alumnos);
                        printf("%9i|",maestros[i][j].datos_de_asignatura.horario_de_inicio);
                        printf("%7s|",maestros[i][j].datos_de_asignatura.turno);


                    }
                }
            }

        }
        if(menu==3)
        {
            printf("\nModificar cantidad de Alumnos\n");
            printf("|  Nombre  | Materia |No. Alumnos|");
            for(i=0;i<numero_de_personas;i++)
            {

                printf("\n|%10s|",maestros[i][0].nombre);




                for(j=0;j<numero_datos;j++)
                {
                    //printf("Conglomerado de datos : %i \n",arr[i][j]);
                    if(j<numero_datos-1)
                    {

                        printf("%9s|",maestros[i][j].datos_de_asignatura.nombre_de_materia);
                        printf("%11i|",maestros[i][j].datos_de_asignatura.cantidad_de_alumnos);
                        /*printf("%9i|",maestros[i][j].datos_de_asignatura.horario_de_inicio);
                        printf("%7s|",maestros[i][j].datos_de_asignatura.turno);*/
                        printf("\n|%10s|",espacio_vacio,espacio_vacio);
                    }
                    if(j==numero_datos-1) //elimina las dobles rallas
                    {
                        printf("%9s|",maestros[i][j].datos_de_asignatura.nombre_de_materia);
                        printf("%11i|",maestros[i][j].datos_de_asignatura.cantidad_de_alumnos);
                        /*printf("%9i|",maestros[i][j].datos_de_asignatura.horario_de_inicio);
                        printf("%7s|",maestros[i][j].datos_de_asignatura.turno);*/


                    }
                }
            }

            int maestro_seleccionado, materia_seleccionada;
            printf("\nSeleccione la Maestro\n");
            for(i=0;i<numero_de_personas;i++)
            {
                printf(" %i |%10s|\n",i+1,maestros[i][0].nombre);
            }
            scanf("%i",&maestro_seleccionado);
            maestro_seleccionado-=1;//para el array[0]
            numero_datos= array_dimension[maestro_seleccionado];
            printf("Seleccione la Materia\n");


            for(i=0;i<numero_datos;i++)
            {
                printf("|%i|%10s|",i+1,maestros[maestro_seleccionado][i].datos_de_asignatura.nombre_de_materia);
                printf("%i|\n",maestros[maestro_seleccionado][i].datos_de_asignatura.cantidad_de_alumnos);
            }
            int actualizacion_materia;
            scanf("%i",&materia_seleccionada);
            materia_seleccionada-=1;
            printf("Digite el n\FAmero de alumnos acual");
            printf("%10s \n %i -> ",maestros[maestro_seleccionado][materia_seleccionada].datos_de_asignatura.nombre_de_materia,maestros[maestro_seleccionado][materia_seleccionada].datos_de_asignatura.cantidad_de_alumnos);
            scanf("%i",&actualizacion_materia);
            maestros[maestro_seleccionado][materia_seleccionada].datos_de_asignatura.cantidad_de_alumnos = actualizacion_materia;

            //forma de tabla
            printf("Forma de Tabla\n");
            printf("|  Nombre  | Edad | Materia |No. Alumnos| Horario | Turno |",maestros[i][0].nombre,maestros[i][0].edad);
            for(i=0;i<numero_de_personas;i++)
            {

                printf("\n|%10s|%6i|",maestros[i][0].nombre,maestros[i][0].edad);




                for(j=0;j<numero_datos;j++)
                {
                    //printf("Conglomerado de datos : %i \n",arr[i][j]);
                    if(j<numero_datos-1)
                    {

                        printf("%9s|",maestros[i][j].datos_de_asignatura.nombre_de_materia);
                        printf("%11i|",maestros[i][j].datos_de_asignatura.cantidad_de_alumnos);
                        printf("%9i|",maestros[i][j].datos_de_asignatura.horario_de_inicio);
                        printf("%7s|",maestros[i][j].datos_de_asignatura.turno);
                        printf("\n|%10s|%6s|",espacio_vacio,espacio_vacio);
                    }
                    if(j==numero_datos-1) //elimina las dobles rallas
                    {
                        printf("%9s|",maestros[i][j].datos_de_asignatura.nombre_de_materia);
                        printf("%11i|",maestros[i][j].datos_de_asignatura.cantidad_de_alumnos);
                        printf("%9i|",maestros[i][j].datos_de_asignatura.horario_de_inicio);
                        printf("%7s|",maestros[i][j].datos_de_asignatura.turno);


                    }
                }
            }


        }
        printf("Universidad de la Soborna");
        desplegar(arreglo,tam_cadena);
        printf("\nSeleccione la opcion\n1.Seleccionar Maestro\n2.Imprimir Tabla\n3.Modificar No. Alumnos\n");
        scanf("%i",&menu);
    }





    /*
    for(i=0;i<numero_datos;i++)
    {
        printf("\nConglomerado de datos : %i ",arr[numero_escaneado][i]);
        printf("Nombre de la materia : %s",maestros[numero_escaneado][i].datos_de_asignatura.nombre_de_materia);
      printf("Cantidad de alumnos : %i",maestros[numero_escaneado][i].datos_de_asignatura.cantidad_de_alumnos);
      printf("Horario de inicio : %i",maestros[numero_escaneado][i].datos_de_asignatura.horario_de_inicio);
      printf("Turno : %s",maestros[numero_escaneado][i].datos_de_asignatura.turno);
    }

  */





    printf("\nHorario ascendente...\nvendra en el recurse, pues no logre linkear el horario con la persona... :c"); //necesito filtrar por turnos M y V para poner un if y asi eliminar los nulos




    return 0;
}

int tamanoCadena(char cadena[])
{

    int largo=0;
    while (cadena[largo]!='\0')	largo++;

    return largo;
}

void desplegar (char * arreglo, int tam)
{
//Desplegar
    cont = 1;
    for(i=0;i<tam;i++)
    {
        printf("%c",*(arreglo + i));
        cont++;
    }
}

