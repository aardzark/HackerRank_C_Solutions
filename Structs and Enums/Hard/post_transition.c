/***************************
 * Author: Zachary Perales *
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_STRING_LENGTH 6

// Credit goes to @bugfeeder: https://stackoverflow.com/a/10959486 for the below definition.
#define assert__(x) for ( ; !(x) ; assert(x) )

struct package {
    char* id;
    int weight;
};

typedef struct package package;

struct post_office {
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town {
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;

void print_all_packages(town t) {
    /*
    printf("%s:\n", t.name);

    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);

        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
    */
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    /*
    post_office target_office = target->offices[target_office_index];
    post_office source_office = source->offices[source_office_index];
    printf("Source town name: %s:\n", source->name);
    printf("Source office, %d, packages:\n", source_office_index);
    printf("Source office # of packages: %d\n", source_office.packages_count);
    for (int i = 0; i < source_office.packages_count; i++) {
        printf("Package: %s\n", source_office.packages[i].id);
    }

    printf("Target town name: %s:\n", target->name);
    printf("Target office, %d, packages:\n", target_office_index);
    printf("Target office before adding packages:\n");
    printf("Target office min_weight of package: %d\n", target_office.min_weight);
    printf("Target office max_weight of package: %d\n", target_office.max_weight);
    printf("Target office # of packages: %d\n", target_office.packages_count);
    for (int i = 0; i < target_office.packages_count; i++) {
        printf("Package: %s\n", target_office.packages[i].id);
    }

    int total = 0;
    for (int i = 0; i < source->offices[source_office_index].packages_count; i++) {
        if (target_office.min_weight <= source_office.packages[i].weight <= target_office.max_weight) {
            total++;
            sent_packages = realloc(target_office.packages, sizeof(package)*total);
            sent_packages[i] = source_office.packages[i];
        }
    }
    target_office.packages = sent_packages;
    target_office.packages_count += total;

    printf("Target office after adding packages:\n");
    for (int i = 0; i < target_office.packages_count; i++) {
        printf("Package: %s\n", target_office.packages[i].id);
    }
    */
}

town town_with_most_packages(town* towns, int towns_count) {
    return towns[0];
}

town* find_town(town* towns, int towns_count, char* name) {
    return &towns[0];
}

town* initialize_towns(int towns_count) {
    town* towns_test = malloc(sizeof(town)*towns_count);
    towns_test[0].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
    towns_test[0].name = 'A';
    towns_test[0].offices_count = 2;
    towns_test[0].offices = malloc(sizeof(post_office) * towns_test[0].offices_count);
    towns_test[0].offices[0].packages_count = 2;
    towns_test[0].offices[0].min_weight = 1;
    towns_test[0].offices[0].max_weight = 3;
    towns_test[0].offices[0].packages = malloc(sizeof(package) * towns_test[0].offices[0].packages_count);
    towns_test[0].offices[0].packages[0].id = 'a';
    towns_test[0].offices[0].packages[0].weight = 2;
    towns_test[0].offices[0].packages[1].id = 'b';
    towns_test[0].offices[0].packages[1].weight = 3;
    towns_test[0].offices[1].packages_count = 1;
    towns_test[0].offices[1].min_weight = 2;
    towns_test[0].offices[1].max_weight = 4;
    towns_test[0].offices[1].packages = malloc(sizeof(package) * towns_test[0].offices[1].packages_count);
    towns_test[0].offices[1].packages[0].id = 'c';
    towns_test[0].offices[1].packages[0].weight = 2;
    towns_test[1].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
    towns_test[1].name = 'B';
    towns_test[1].offices_count = 1;
    towns_test[1].offices = malloc(sizeof(post_office) * towns_test[1].offices_count);
    towns_test[1].offices[0].packages_count = 4;
    towns_test[1].offices[0].min_weight = 1;
    towns_test[1].offices[0].max_weight = 4;
    towns_test[1].offices[0].packages = malloc(sizeof(package) * towns_test[1].offices[0].packages_count);
    towns_test[1].offices[0].packages[0].id = 'd';
    towns_test[1].offices[0].packages[0].weight = 1;
    towns_test[1].offices[0].packages[1].id = 'e';
    towns_test[1].offices[0].packages[1].weight = 2;
    towns_test[1].offices[0].packages[2].id = 'f';
    towns_test[1].offices[0].packages[2].weight = 3;
    towns_test[1].offices[0].packages[3].id = 'h';
    towns_test[1].offices[0].packages[3].weight = 4;
    return towns_test;
}

void precondition_unit_tests_for_send_all_acceptable_packages(town* towns_test) {
    assert__('A' == towns_test[0].name) {
        printf("towns_test[0].name should equal 'A' but equals %s\n", towns_test[0].name);
    }

    assert__(2 == towns_test[0].offices_count) {
        printf("towns_test[0].offices_count should equal 2 but equals %d\n", towns_test[0].offices_count);
    }

    assert__(2 == towns_test[0].offices[0].packages_count) {
        printf("towns_test[0].offices[0].packages_count should equal 2 but equals %d\n", towns_test[0].offices[0].packages_count);
    }

    assert__(1 == towns_test[0].offices[0].min_weight) {
        printf("towns_test[0].offices[0].min_weight should equal 1 but equals %d\n", towns_test[0].offices[0].min_weight);
    }

    assert__(3 == towns_test[0].offices[0].max_weight) {
        printf("towns_test[0].offices[0].max_weight should equal 3 but equals %d\n", towns_test[0].offices[0].max_weight);
    }

    assert__('a' == towns_test[0].offices[0].packages[0].id) {
        printf("towns_test[0].offices[0].packages[0].id should equal 'a' but equals %s\n", towns_test[0].offices[0].packages[0].id);
    }

    assert__(2 == towns_test[0].offices[0].packages[0].weight) {
        printf("towns_test[0].offices[0].packages[0].weight should equal 2 but equals %d\n", towns_test[0].offices[0].packages[0].weight);
    }

    assert__('b' == towns_test[0].offices[0].packages[1].id) {
        printf("towns_test[0].offices[0].packages[1].id should equal 'b' but equals %s\n", towns_test[0].offices[0].packages[1].id);
    }

    assert__(3 == towns_test[0].offices[0].packages[1].weight) {
        printf("towns_test[0].offices[0].packages[1].weight should equal 3 but equals %d\n", towns_test[0].offices[0].packages[1].weight);
    }

    assert__(1 == towns_test[0].offices[1].packages_count) {
        printf("towns_test[0].offices[1].packages_count should equal 1 but equals %d\n", towns_test[0].offices[1].packages_count);
    }

    assert__(2 == towns_test[0].offices[1].min_weight) {
        printf("towns_test[0].offices[1].min_weight should equal 2 but equals %d\n", towns_test[0].offices[1].min_weight);
    }

    assert__(4 == towns_test[0].offices[1].max_weight) {
        printf("towns_test[0].offices[1].max_weight should equal 4 but equals %d\n", towns_test[0].offices[1].max_weight);
    }

    assert__('c' == towns_test[0].offices[1].packages[0].id) {
        printf("towns_test[0].offices[1].packages[0].id should equal 'c' but equals %s\n", towns_test[0].offices[1].packages[0].id);
    }

    assert__(2 == towns_test[0].offices[1].packages[0].weight) {
        printf("towns_test[0].offices[1].packages[0].weight should equal 2 but equals %d\n", towns_test[0].offices[1].packages[0].weight);
    }

    assert__('B' == towns_test[1].name) {
        printf("towns_test[1].name should equal 'B' but equals %s\n", towns_test[1].name);
    }

    assert__(1 == towns_test[1].offices_count) {
        printf("towns_test[1].offices_count should equal 1 but equals %d\n", towns_test[1].offices_count);
    }

    assert__(4 == towns_test[1].offices[0].packages_count) {
        printf("towns_test[1].offices[0].packages_count should equal 4 but equals %d\n", towns_test[1].offices[0].packages_count);
    }

    assert__(1 == towns_test[1].offices[0].min_weight) {
        printf("towns_test[1].offices[0].min_weight should equal 1 but equals %d\n", towns_test[1].offices[0].min_weight);
    }

    assert__(4 == towns_test[1].offices[0].max_weight) {
        printf("towns_test[1].offices[0].max_weight should equal 4 but equals %d\n", towns_test[1].offices[0].max_weight);
    }

    assert__('d' == towns_test[1].offices[0].packages[0].id) {
        printf("towns_test[1].offices[0].packages[0].id should equal 'd' but equals %s\n", towns_test[1].offices[0].packages[0].id);
    }

    assert__(1 == towns_test[1].offices[0].packages[0].weight) {
        printf("towns_test[1].offices[0].packages[0].weight should equal 1 but equals %d\n", towns_test[1].offices[0].packages[0].weight);
    }

    assert__('e' == towns_test[1].offices[0].packages[1].id) {
        printf("towns_test[1].offices[0].packages[1].id should equal 'e' but equals %s\n", towns_test[1].offices[0].packages[1].id);
    }

    assert__(2 == towns_test[1].offices[0].packages[1].weight) {
        printf("towns_test[1].offices[0].packages[1].weight should equal 2 but equals %d\n", towns_test[1].offices[0].packages[1].weight);
    }

    assert__('f' == towns_test[1].offices[0].packages[2].id) {
        printf("towns_test[1].offices[0].packages[2].id should equal 'f' but equals %s\n", towns_test[1].offices[0].packages[2].id);
    }

    assert__(3 == towns_test[1].offices[0].packages[2].weight) {
        printf("towns_test[1].offices[0].packages[2].weight should equal 3 but equals %d\n", towns_test[1].offices[0].packages[2].weight);
    }

    assert__('h' == towns_test[1].offices[0].packages[3].id) {
        printf("towns_test[1].offices[0].packages[3].id should equal 'h' but equals %s\n", towns_test[1].offices[0].packages[3].id);
    }

    assert__(4 == towns_test[1].offices[0].packages[3].weight) {
        printf("towns_test[1].offices[0].packages[3].weight should equal 4 but equals %d\n", towns_test[1].offices[0].packages[3].weight);
    }
}

void postcondition_unit_tests_for_send_all_acceptable_packages(town* towns_test) {
}

int main() {
    int towns_count = 2;
    town* towns_test = initialize_towns(towns_count);
    precondition_unit_tests_for_send_all_acceptable_packages(towns_test);

    /*
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town)*towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];
    while (queries--) {
        int type;
        scanf("%d", &type);
        switch (type) {
            case 1:
                scanf("%s", town_name);
                town* t = find_town(towns, towns_count, town_name);
                print_all_packages(*t);
                break;
            case 2:
                scanf("%s", town_name);
                town* source = find_town(towns, towns_count, town_name);
                int source_index;
                scanf("%d", &source_index);
                scanf("%s", town_name);
                town* target = find_town(towns, towns_count, town_name);
                int target_index;
                scanf("%d", &target_index);
                send_all_acceptable_packages(source, source_index, target, target_index);
                break;
            case 3:
                printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
                break;
        }
    }
    */

    return 0;
}
