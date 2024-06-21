/*
** EPITECH PROJECT, 2024
** my_paint.h
** File description:
** library for my_paint function
*/

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Types.h>
    #include <stddef.h>
    #include <stdlib.h>
    #define SP_1 (*config)->extra.splus
    #define TP_1 (*config)->extra.tplus
    #define SM_1 (*config)->extra.sminus
    #define TM_1 (*config)->extra.tminus

static const char HELP[] =
"Bonjour ! Bienvenue sur my_paints, projet realiser par Jeremy Armijo et "
"Jiachen Li\n\n"
"Je vais vous presenter l'interface utilisateur de notre projet.\n"
"Comme vous pouvez l'observer, vous retrouvez 5 icones et une palette "
"de couleur de gauche a droite, dans l'ordre :\n"
"-Fichier : qui contient de haut en bas les fonctions 'Nouveau fichier', "
"'Ouvrir un fichier', 'Sauvegarder le fichier'.(Pour l'instant vous pouvez "
"seulement sauvegarder un seule fichier et ouvrir ce meme fichier)\n"
"-Outils : qui contient de haut en bas les fonctions 'Le stylo', 'La gomme'"
", 'La souris'(Par defaut le stylo dessine en cercle et la gomme en carre)\n"
"-Help : L'espace dans laquelle vous etre actuellement\n"
"-Palette : selectionner la couleur de votre choix en un simple clic !\n\n"
"-Diminuer : diminue l'epaisseur ou la taille du outil en appuyant dessus\n"
"-Augmenter : augmente l'epaisseur ou la taille du outil en appuyant dessus\n"
"Voila C'en ai fini pour le help, recliquez sur help sur le "
"clavier pour quitter cet espace !";

enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct path_sprites_s {
    char *basic;
    char *is_hover;
} path_sprites_t;

typedef struct menu_s {
    float radius;
    sfRectangleShape *rect;
    sfVector2f position;
    sfSprite *pencil;
    sfTexture *draw;
    sfVector2f size;
    sfTexture *texture;
    sfSprite *sprite;
    path_sprites_t *paths;
    struct menu_s *next;
} menu_t;

typedef struct button_s {
    int is_active;
    int is_released;
    float radius;
    int nb_button;
    sfRectangleShape *rect;
    sfVector2f size;
    sfVector2f position;
    enum e_gui_state state;
    sfTexture *texture;
    sfSprite *sprite;
} button_t;

typedef struct all_button_s {
    button_t *pencilplus;
    button_t *pencilminus;
    button_t *colors;
    button_t *button;
    button_t *button2;
    button_t *button3;
    menu_t *menu;
    menu_t *menu2;
    menu_t *menu3;
} all_button_t;

typedef struct options_tools_s {
    sfSprite *splus;
    sfTexture *tplus;
    sfSprite *sminus;
    sfTexture *tminus;
    button_t *colors;
} options_tools_t;

typedef struct global_s {
    sfRenderWindow *window;
    sfRenderTexture *paper;
    sfSprite *paper_sp;
    const sfTexture *paper_text;
    sfEvent event;
    sfBool click;
    sfColor pen_color;
    sfText *help;
    sfFont *help_font;
    sfBool print_help;
    options_tools_t extra;
} global_t;

typedef struct tool_s {
    sfSprite *pencil;
    int is_active;
    sfTexture *draw;
    sfTexture *erase;
    sfCircleShape *use_pencil;
    sfRectangleShape *use_eraser;
    float radius;
    sfSprite *eraser;
} tool_t;

typedef struct pos_button_s {
    int coef_pos_x;
    int scale;
} pos_button_t;

// Change button stat | handle_button.c
sfBool is_hover(button_t *button, global_t *config);
sfBool is_button_pressed(button_t *button, global_t *config);

// Change menu stat | struct_action_button.c
sfBool is_hover_in_stuct(menu_t *button, global_t *config);
sfBool is_button_pressed_in_struct(menu_t *button, global_t *config);

// Initialize game status | init_game.c
button_t *init_button(int coef);
sfRenderWindow *init_window(void);
global_t *init_game_status(void);
tool_t *init_tools(void);
void set_init_game(button_t *button, tool_t *tools);

// Init buttons | init_all_button.c
all_button_t *init_all_button(void);
button_t *init_sprites(button_t *button,
    char const *path_sprites, float scale, int pos);

// Display option for menu | options.c
int options_menu1(global_t **config, int i);
int options_menu2(int i);
int options_menu3(global_t **config, int i);

// Use of draw tools | draw_tools.c
void draw_buttons(global_t *config, all_button_t *button);
void set_and_draw_tools(all_button_t *button, global_t *config);
void draw_tools(tool_t **tools, global_t **config,
    sfVector2i *mouse_pos, all_button_t **button);
void set_options_sprites_plus(global_t **config,
    float scale, float x, float y);
void set_options_sprites_minus(global_t **config,
    float scale, float x, float y);
void options_tools_button(all_button_t **button, global_t *config);
void draw_rectangle_on_render_text(tool_t **tools, global_t **config,
    sfVector2f mouse_tmp);
void draw_circle_on_render_text(tool_t **tools, global_t **config,
    sfVector2f mouse_tmp);

// initialize menu | init_menu.c
menu_t *init_menu(int x, int y, char *str1, char *str2);
menu_t *push_new_button(menu_t **menu, int x, int y, path_sprites_t *paths);

// Print the menu and button bar | print_menu.c
void button_management(button_t *button, global_t *config, char *path_sprite);
int print_menu(menu_t **menu, global_t **config, button_t **button, int nb);
sfBool is_button_menu_pressed(sfRectangleShape *rect,
    global_t *config, button_t *button);

// Looping the game | loop_paints.c
void set_pos_tools_button_default(all_button_t *button, tool_t *tools,
    sfVector2i *mouse_pos);
void set_sprite(button_t *button, char *path_sprite);
void check_event_type(global_t *config);
void loop_window(global_t **config, all_button_t **button, tool_t **tools);

// set all menu | set_menu.c
void set_menu1(all_button_t *button, global_t *config, tool_t **tools);
void set_menu2(all_button_t *button, global_t *config, tool_t *tools);
void set_menu3(all_button_t *button, global_t *config, tool_t **tools);

// Destroy all cfsml issue and free struct | destroy.all.c
void destroy_all(global_t *config, tool_t *tools);
void free_button(button_t *button1, button_t *button2, button_t *button3);

int nb_of_pointers(menu_t **str1);
char *duplicate_string(char const *src);
int pos_not_button(all_button_t *button, global_t *config);


#endif /* MY_PAINT_H_ */
