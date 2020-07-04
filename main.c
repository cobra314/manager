#include <stdio.h>
#include <string.h>

#include "utils/funciones.h"
#include "structs/maestro.h"
#include "structs/universidad.h"
#include "utils/cadenaUtils.h"

int main()
{
    struct Universidad universidad;
    universidad = obtenerUniversidad();

    printf("Universisdad : ");
    imprimir(universidad.nombre, universidad.tamanio_nombre);

    printf("\nIngrese los datos de los maestros a continuacion.\n");

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
        printf("Digite el nombre del maestro %i : ",contador_personas);
        scanf("%s",nombre_solicitado);
        printf("Digite la edad del maestro : ");
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
            printf("Escriba el nombre de la materia : ");
            scanf("%s",nombre_materia_solicitado);
            printf("Digite la cantidad de alumnos de la materia : ");
            scanf("%i",&cantidad_de_alumnos);
            printf("Digite el horario de inicio de la materia : ");
            scanf("%i",&horario_de_materia);
            printf("Digite el Turno : ");
            scanf("%s",turno_solicitado);

            strcpy(maestros[i][j].datos_de_asignatura.nombre_de_materia,nombre_materia_solicitado); //asigno a struct
            maestros[i][j].datos_de_asignatura.cantidad_de_alumnos=cantidad_de_alumnos;
            maestros[i][j].datos_de_asignatura.horario_de_inicio=horario_de_materia;
            strcpy(maestros[i][j].datos_de_asignatura.turno,turno_solicitado);
        }
        //agregar for i=0  for j=0
    }
    printf("La cantidad extraida de datos de persona en orden es : ");
    for(i=0;i<numero_de_personas;i++)
    {
        printf("%i ",array_dimension[i]); //imprime el Arreglo que extrae la cantidad de c
    }

    printf("\nSeleccione al Maestro : \n");
    for(i=0;i<numero_de_personas;i++)
    {
        printf(" %i |%10s|\n",i+1,maestros[i][0].nombre);
    }
    printf("\n opcion elegida : ");
    scanf("%i",&numero_escaneado);
    numero_escaneado-=1;
    numero_datos= array_dimension[numero_escaneado]; //le asigno el numero buscado al arra_dimension para obtener el numero de sus datos

    printf("Nombre : %s\n", maestros[numero_escaneado][0].nombre);
    printf("Edad : %i\n", maestros[numero_escaneado][0].edad);
    for(i=0;i<numero_datos;i++)
    {
        printf("\n - Materias - \n");
        printf("Nombre de la materia : %s \n",maestros[numero_escaneado][i].datos_de_asignatura.nombre_de_materia);
        printf("Cantidad de alumnos : %i \n",maestros[numero_escaneado][i].datos_de_asignatura.cantidad_de_alumnos);
        printf("Horario de inicio : %i \n",maestros[numero_escaneado][i].datos_de_asignatura.horario_de_inicio);
        printf("Turno : %s \n",maestros[numero_escaneado][i].datos_de_asignatura.turno);
    }

    int menu;
    printf("\nSeleccione una opcion \n 1.-Maestro \n 2.-Imprimir Materias \n 3.-Modificar numero de alumnos");
    printf("\n opcion elegida : ");
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
        printf("\nSeleccione una opcion \n 1.-Maestro \n 2.-Imprimir Materias \n 3.-Modificar numero de alumnos");
        printf("\n opcion elegida : ");
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
