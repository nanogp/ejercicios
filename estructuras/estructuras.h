#define LARGO_ITEM_MENU 50
#define LARGO_DESCRIPCION 100
#define NRO_MAX_OPCIONES_MENU 10
#define NRO_MAX_PRODUCTOS 20

typedef struct
{
    int cantOpciones;
    int codigos[NRO_MAX_OPCIONES_MENU];
    char descripciones[NRO_MAX_OPCIONES_MENU][LARGO_ITEM_MENU];
} eMenu;

typedef struct
{
    int codigo;
    char descripcion[LARGO_DESCRIPCION];
    unsigned int stock;
    float precioCosto;
} eProducto;
