#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* nuevoEmpleado();

int mostrarEmpleado(Employee* aux);

void employee_delete();

int employee_list(LinkedList* pArrayListEmployee, int len);

int employee_NewId(LinkedList* pArrayListEmployee);


int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(void* e1, void* e2);

int employee_IndexById(LinkedList* pArrayListEmployee,int id);


#endif // employee_H_INCLUDED
