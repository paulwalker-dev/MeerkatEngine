#include "Extras.h"
#include "Dynamic.h"
#include <stdarg.h>
#include <string.h>

List *entity_data_get(Entity *e)
{
    ComponentData *cd;
    Dynamic *d;
    List *data;
    int i;

    d = NULL;
    data = list_create();
    for (i = 0; i < e->data->length; ++i) {
        cd = list_get(e->data, i);
        list_append(data, cd);
        if (!strcmp(cd->name, "Dynamic")) {
            d = cd->data;
        }
    }
    if (d) {
        for (i = 0; i < d->data->length; ++i) {
            cd = list_get(d->data, i);
            list_append(data, cd);
        }
    }

    return data;
}

List *component_list_create(Store *s, char *component, ...)
{
    Component *c;
    List *l;
    va_list ap;

    l = list_create();

    va_start(ap, component);
    while (component) {
        c = component_find(s->components, component);
        list_append(l, c);
        component = va_arg(ap, char *);
    }
    va_end(ap);

    return l;
}
