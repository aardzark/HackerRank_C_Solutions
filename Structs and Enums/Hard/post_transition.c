/***************************
 * Author: Zachary Perales *
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
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
    printf("%s:\n", t.name);

    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);

        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    // Count the number of packages being sent from the source town's office to the target town's office
    int sending_packages_count = 0;
    for (int i = 0; i < source->offices[source_office_index].packages_count; i++) {
        if (target->offices[target_office_index].min_weight <= source->offices[source_office_index].packages[i].weight
                && source->offices[source_office_index].packages[i].weight <= target->offices[target_office_index].max_weight) {
            sending_packages_count++;
        }
    }

    // Initialize a package pointer and allocate the exact amount of memory needed for the number of packages that will be sent to the target office.
    package* sent_packages = malloc(sizeof(package) * sending_packages_count);
    // Initialize a package pointer and allocate the exact amount of memory needed for the number of packages that will be returned to the source office.
    package* returned_packages = malloc(sizeof(package) * (source->offices[source_office_index].packages_count - sending_packages_count));
    // Iterator to keep track of the current index for the sent_packages array
    int packages_sent = 0;
    // Iterator to keep track of the current index for the returned_packages array
    int packages_returned = 0;
    // Iterate through the source office packages and redirect each package to either the sent_packages array or the returned_packages array
    for (int i = 0; i < source->offices[source_office_index].packages_count; i++) {
        if (target->offices[target_office_index].min_weight <= source->offices[source_office_index].packages[i].weight
            && source->offices[source_office_index].packages[i].weight <= target->offices[target_office_index].max_weight) {
            sent_packages[packages_sent] = source->offices[source_office_index].packages[i];
            packages_sent++;
        } else {
            returned_packages[packages_returned] = source->offices[source_office_index].packages[i];
            packages_returned++;
        }
    }

    // Reallocate the exact amount memory needed to store the array of sent packages appended to the array of existing packages at the target office
    target->offices[target_office_index].packages = (package*)realloc(target->offices[target_office_index].packages, sizeof(package) * (target->offices[target_office_index].packages_count + packages_sent));
    // Append the array of sent packages to the existing array of packages at the target office
    memmove(target->offices[target_office_index].packages + target->offices[target_office_index].packages_count, sent_packages, sizeof(package) * packages_sent);
    free(sent_packages);
    target->offices[target_office_index].packages_count += sending_packages_count;

    // Reallocate the exact amount memory needed to store the array of returned packages at the source office
    source->offices[source_office_index].packages = (package*)realloc(source->offices[source_office_index].packages, sizeof(package) * (packages_returned));
    // Copy the array of returned packages to the start of the packages array at the source office and overwrite it
    memmove(source->offices[source_office_index].packages, returned_packages, sizeof(package) * packages_returned);
    free(returned_packages);
    source->offices[source_office_index].packages_count -= sending_packages_count;
}

town town_with_most_packages(town* towns, int towns_count) {
    town* town_with_most_packages = malloc(sizeof(town));

    int previous_packages_count = 0;
    int current_packages_count = 0;
    for (int i = 0; i < towns_count; i++) {
        for (int j = 0; j < towns[i].offices_count; j++) {
            for(int k = 0; k < towns[i].offices[j].packages_count; k++) {
                current_packages_count++;
            }
        }
        if (current_packages_count > previous_packages_count) {
            previous_packages_count = current_packages_count;
            town_with_most_packages = &towns[i];
        }
        current_packages_count = 0;
    }
    return town_with_most_packages[0];
}

town* find_town(town* towns, int towns_count, char* name) {
    town* town = malloc(sizeof(town));
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            town = &towns[i];
        }
    }
    return town;
}

// Beginning of code refactor to combine the two methods of HackerRank's method of initializing towns and mine for unit tests with assert statements
town* init_towns(int town_count, char town_name[], int office_count[], int package_metadata[], char package_id[], int package_weight[], int manual_init) {
    //int tc = (manual_init) ? town_count : scanf("%d");
    town* towns = malloc(sizeof(town) * town_count);

    int packages_processed = 0;
    int offices_processed = 0;

    for (int i = 0; i < town_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);

        (manual_init) ? towns[i].name[0] = town_name[i] : scanf("%s", towns[i].name);
        (manual_init) ? towns[i].offices_count = office_count[i] : scanf("%d", &towns[i].offices_count);

        towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);

        for (int j = 0; j < towns[i].offices_count; j++) {
            (manual_init) ? towns[i].offices[j].packages_count = package_metadata[offices_processed * 3] : scanf("%d", &towns[i].offices[j].packages_count);
            (manual_init) ? towns[i].offices[j].min_weight = package_metadata[(offices_processed * 3) + 1] : scanf("%d", &towns[i].offices[j].min_weight);
            (manual_init) ? towns[i].offices[j].max_weight = package_metadata[(offices_processed * 3) + 2] : scanf("%d", &towns[i].offices[j].max_weight);

            towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);

            offices_processed++;
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);

                (manual_init) ? towns[i].offices[j].packages[k].id = package_id[packages_processed] : scanf("%s", towns[i].offices[j].packages[k].id);
                (manual_init) ? towns[i].offices[j].packages[k].weight = package_weight[packages_processed] : scanf("%d", &towns[i].offices[j].packages[k].weight);

                packages_processed++;
            }
        }
    }

    return towns;
}

void precondition_unit_tests_for_towns_test (town* towns_test) {
    assert__('A' == *towns_test[0].name) {
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

    assert__('B' == *towns_test[1].name) {
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

void precondition_unit_tests_for_send_all_acceptable_packages (town* towns_test){
    assert__(2 == towns_test[0].offices[0].packages_count) {
        printf("towns_test[0].offices[0].packages_count should equal 2 but equals %d\n", towns_test[0].offices[0].packages_count);
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

    assert__('c' == towns_test[0].offices[1].packages[0].id) {
        printf("towns_test[0].offices[1].packages[0].id should equal 'c' but equals %s\n", towns_test[0].offices[1].packages[0].id);
    }

    assert__(2 == towns_test[0].offices[1].packages[0].weight) {
        printf("towns_test[0].offices[1].packages[0].weight should equal 2 but equals %d\n", towns_test[0].offices[1].packages[0].weight);
    }
}

void postcondition_unit_tests_for_send_all_acceptable_packages(town* towns_test) {
    assert__(0 == towns_test[0].offices[0].packages_count) {
        printf("towns_test[0].offices[0].packages_count should equal 0 but equals %d\n", towns_test[0].offices[0].packages_count);
    }

    assert__(3 == towns_test[0].offices[1].packages_count) {
        printf("towns_test[0].offices[1].packages_count should equal 3 but equals %d\n", towns_test[0].offices[1].packages_count);
    }

    assert__('c' == towns_test[0].offices[1].packages[0].id) {
        printf("towns_test[0].offices[1].packages[0].id should equal 'c' but equals %s\n", towns_test[0].offices[1].packages[0].id);
    }

    assert__(2 == towns_test[0].offices[1].packages[0].weight) {
        printf("towns_test[0].offices[1].packages[0].weight should equal 2 but equals %d\n", towns_test[0].offices[1].packages[0].weight);
    }

    assert__('a' == towns_test[0].offices[1].packages[1].id) {
        printf("towns_test[0].offices[1].packages[1].id should equal 'a' but equals %s\n", towns_test[0].offices[1].packages[1].id);
    }

    assert__(2 == towns_test[0].offices[1].packages[1].weight) {
        printf("towns_test[0].offices[1].packages[1].weight should equal 2 but equals %d\n", towns_test[0].offices[1].packages[1].weight);
    }

    assert__('b' == towns_test[0].offices[1].packages[2].id) {
        printf("towns_test[0].offices[1].packages[2].id should equal 'b' but equals %s\n", towns_test[0].offices[1].packages[2].id);
    }

    assert__(3 == towns_test[0].offices[1].packages[2].weight) {
        printf("towns_test[0].offices[1].packages[2].weight should equal 3 but equals %d\n", towns_test[0].offices[1].packages[2].weight);
    }
}

int main() {
    town* towns_test = init_towns(2, (char[2]){'A', 'B'},
                                  (int[2]){2, 1},
                                  (int[9]){2, 1, 3, 1, 2, 4, 4, 1, 4},
                                  (char[7]){'a', 'b', 'c', 'd', 'e', 'f', 'h'},
                                  (int[7]){2, 3, 2, 1, 2, 3, 4},
                                  1);

    precondition_unit_tests_for_towns_test(towns_test);

    precondition_unit_tests_for_send_all_acceptable_packages(towns_test);
    send_all_acceptable_packages(&towns_test[0], 0, &towns_test[0], 1);
    postcondition_unit_tests_for_send_all_acceptable_packages(towns_test);

    int towns_count = malloc(sizeof(int));
    scanf("%d", &towns_count);
    town* towns = init_towns(towns_count, NULL, NULL, NULL, NULL, NULL, 0);

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


    return 0;
}




