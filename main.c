#include <stdio.h>
#include <string.h>

int main() {
    int i, j, opc;
    int cantidadEstudiantes = 5;
    int cantidadMaterias = 3;
    int datosIngresados = 0;
    char ids[5][10];
    char nombresEstudiantes[5][50];
    char nombresMaterias[3][50];
    float calificaciones[5][3];

    while (1) {
        printf("\nMenu de opciones\n");
        printf("1. Ingresar datos de los estudiantes:\n");
        printf("2. Mostrar tabla de calificaciones:\n");
        printf("3. Calcular promedio de los estudiantes:\n");
        printf("4. Mostrar la calificacion mas alta y baja por estudiante:\n");
        printf("5. Mostrar la cantidad de estudiantes aprobados o reprobados:\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d", &opc);

        if (opc == 1) {
            printf("\nIngrese los nombres de las materias:\n");
            for (j = 0; j < cantidadMaterias; j++) {
                printf("Materia %d: ", j + 1);
                scanf(" %[^\n]", nombresMaterias[j]);
            }

            for (i = 0; i < cantidadEstudiantes; i++) {
                sprintf(ids[i], "A%03d", i + 1);
                printf("Estudiante %d (ID: %s)\n", i + 1, ids[i]);
                printf("Ingrese el nombre del estudiante: ");
                scanf(" %[^\n]", nombresEstudiantes[i]);

                for (j = 0; j < cantidadMaterias; j++) {
                    float nota;
                    int resultado;

                    do {
                        printf("  Ingrese nota de %s (0 a 10): ", nombresMaterias[j]);
                        resultado = scanf("%f", &nota);

                        if (resultado != 1 || nota < 0 || nota > 10) {
                            printf("  Entrada invalida\n");
                            while(getchar() != '\n'); 
                        } else {
                            calificaciones[i][j] = nota;
                            break;
                        }

                    } while (1);
                }
            }
            datosIngresados = 1;

        } else if (opc == 2) {
            if (!datosIngresados) {
                printf("Datos inexistentes, debe ingresar datos (opcion 1).\n");
                break;
            }
            printf("\nTabla de calificaciones:\n");
            printf("%-6s %-20s", "ID", "Estudiante");
            for (j = 0; j < cantidadMaterias; j++)
            {
                printf("%-12s", nombresMaterias[j]);
            }
            printf("\n");

            for (i = 0; i < cantidadEstudiantes; i++)
            {
                printf("%-6s %-20s", ids[i], nombresEstudiantes[i]);
                for (j = 0; j < cantidadMaterias; j++)
                {
                    printf("%-12.2f", calificaciones[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            printf("Tabla de calificaciones mostrada.\n");
        } else if (opc == 3) {
            if (!datosIngresados) {
                printf("Datos inexistentes, debe ingresar datos (opcion 1).\n");
                continue;
            }
            printf("\nPromedio por estudiante:\n");
            for (i = 0; i < cantidadEstudiantes; i++) {
                float suma = 0;
                for (j = 0; j < cantidadMaterias; j++) {
                    suma += calificaciones[i][j];
                }
                printf("ID %s - %s: %.2f\n", ids[i], nombresEstudiantes[i], suma / cantidadMaterias);
            }

        } else if (opc == 4) {
            if (!datosIngresados) {
                printf("Datos inexistentes, debe ingresar datos (opcion 1).\n");
                continue;
            }
            printf("\nNota mas alta y mas baja por estudiante:\n");
            for (i = 0; i < cantidadEstudiantes; i++) {
                float max = calificaciones[i][0];
                float min = calificaciones[i][0];
                for (j = 1; j < cantidadMaterias; j++) {
                    if (calificaciones[i][j] > max) max = calificaciones[i][j];
                    if (calificaciones[i][j] < min) min = calificaciones[i][j];
                }
                printf("ID %s - %s: Max: %.2f | Min: %.2f\n", ids[i], nombresEstudiantes[i], max, min);
            }
        } else if (opc == 5) {
            if (!datosIngresados) {
                printf("Datos inexistentes, debe ingresar datos (opcion 1).\n");
                continue;
            }
            int aprobados = 0, reprobados = 0;
            for (i = 0; i < cantidadEstudiantes; i++) {
                float promedio = 0;
                for (j = 0; j < cantidadMaterias; j++) {
                    promedio += calificaciones[i][j];
                }
                promedio /= cantidadMaterias;
                if (promedio >= 6.0) {
                    aprobados++;
                } else {
                    reprobados++;
                }
            }
            printf("\nEstudiantes aprobados: %d\n", aprobados);
            printf("Estudiantes reprobados: %d\n", reprobados);

        } else if (opc == 6) {
            printf("Saliendo del programa...\n");
            break;

        } else {
            printf("Opcion invalida\n");
        }
    }

    return 0;
}
