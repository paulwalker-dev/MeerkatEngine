#include "Input.h"

int input_key_status(InputComponent *input, char *name)
{
    InputKey *key;
    int i;

    for (i = 0; i < input->keys->length; ++i) {
        key = list_get(input->keys, i);
        if (!strcmp(key->name, name))
            return key->state;
    }

    return 0;
}

InputKey *input_key_create(char *name, SDL_Keycode code)
{
    InputKey *key;

    key = malloc(sizeof(InputKey));
    key->name = name;
    key->code = code;
    key->state = 0;

    return key;
}

void *cd_input_create()
{
    CD_INIT(Input, cd);

    cd->keys = list_create();
    list_append(cd->keys, input_key_create(
        "jump",
        SDLK_SPACE
    ));
    list_append(cd->keys, input_key_create(
        "left",
        SDLK_a
    ));
    list_append(cd->keys, input_key_create(
        "right",
        SDLK_d
    ));

    return cd;
}

void cd_input_destroy(void *_cd)
{
    InputComponent *cd;
    cd = _cd;

    list_destroy(cd->keys);
    free(cd);
}

Component *c_input_create()
COMPONENT3(Input,
           cd_input_create,
           cd_input_destroy);
