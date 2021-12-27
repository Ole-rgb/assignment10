#include "base.h"

typedef enum {
    NT_DIR,
    NT_FILE,
} NodeType;

typedef struct node_s {
    char name[65];
    NodeType type;
    union {
        struct {
            struct node_s ** nodes;
            int nodes_count;
        } dir;
        struct {
            char * content;
            size_t size;
        } file;
    };
} Node;

Node * make_file(char * name) {
    // TODO
    return NULL;
}

Node * make_directory(char * name) {
    // TODO
    return NULL;
}

void insert_into_directory(Node * directory, Node * new_node) {
    // TODO
}

void print_node(Node * node, char * prefix) {
    // TODO
}

Node * find_node(Node * root, char * path) {
    // TODO
    return NULL;
}

void free_node(Node * node) {
    // TODO
}

int main(void) {
    //report_memory_leaks(true);

    // Create a filesystem
    Node * root = make_directory("");

    // Insert some directories and files
    Node * test_file = make_file("test.txt");
    insert_into_directory(root, test_file);
    insert_into_directory(root, make_file("hello.c"));
    insert_into_directory(root, make_file("world.c"));

    Node * home = make_directory("home");

    Node * user = make_directory("user");
    insert_into_directory(user, make_file("image.jpg"));
    Node * config_file = make_file("config.cfg");
    insert_into_directory(user, config_file);
    insert_into_directory(user, make_file("game.exe"));

    insert_into_directory(home, user);
    insert_into_directory(root, home);

    Node * system = make_directory("system");
    insert_into_directory(system, make_file("8_configuration.txt"));
    insert_into_directory(system, make_file("4_processes.txt"));

    Node * secret = make_directory("secret");
    Node * flag_file = make_file("flag.txt");
    insert_into_directory(secret, flag_file);

    insert_into_directory(root, system);
    insert_into_directory(system, secret);

    insert_into_directory(root, make_file("archive.a"));

    // Output the filesystem's content
    print_node(root, "");

    // Make sure we can extract the contained nodes again:
    // files
    test_equal_i(test_file == find_node(root, "/test.txt"), true);
    test_equal_i(flag_file == find_node(root, "/system/secret/flag.txt"), true);
    test_equal_i(config_file == find_node(root, "/home/user/config.cfg"), true);
    // directory without trailing slash
    test_equal_i(user == find_node(root, "/home/user"), true);
    // directory with trailing slash
    test_equal_i(secret == find_node(root, "/system/secret/"), true);
    // returning root itself
    test_equal_i(root == find_node(root, "/"), true);
    // invalid paths
    test_equal_i(find_node(root, "/test.txt/") == NULL, true);
    test_equal_i(find_node(root, "/doesnot.exist") == NULL, true);
    test_equal_i(find_node(root, "/also/does/not/exist") == NULL, true);
    test_equal_i(find_node(root, "/world.c/invalid") == NULL, true);

    free_node(root);
    return 0;
}
