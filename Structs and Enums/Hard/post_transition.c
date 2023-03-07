/***************************
 * Author: Zachary Perales *
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

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

// A function where packages are sent from the source office and then either returned to the source office or accepted by the target office depending on package weight.
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

// Enables the program to initialize and populate an array of towns either manually with the flag set to 1 or via HackerRank's method of argument scanning if set to 0.
town* initialize_towns(int town_count, char town_name[], int office_count[], int package_metadata[], char package_id[], int package_weight[], int manual_init) {
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

// Tests the initialize_towns() function.
void test_initialize_towns (town* towns_test) {
    assert('A' == *towns_test[0].name);
    assert(2 == towns_test[0].offices_count);
    assert(2 == towns_test[0].offices[0].packages_count);
    assert(1 == towns_test[0].offices[0].min_weight);
    assert(3 == towns_test[0].offices[0].max_weight);
    assert('a' == towns_test[0].offices[0].packages[0].id);
    assert(2 == towns_test[0].offices[0].packages[0].weight);
    assert('b' == towns_test[0].offices[0].packages[1].id);
    assert(3 == towns_test[0].offices[0].packages[1].weight);
    assert(1 == towns_test[0].offices[1].packages_count);
    assert(2 == towns_test[0].offices[1].min_weight);
    assert(4 == towns_test[0].offices[1].max_weight);
    assert('c' == towns_test[0].offices[1].packages[0].id);
    assert(2 == towns_test[0].offices[1].packages[0].weight);
    assert('B' == *towns_test[1].name);
    assert(1 == towns_test[1].offices_count);
    assert(4 == towns_test[1].offices[0].packages_count);
    assert(1 == towns_test[1].offices[0].min_weight);
    assert(4 == towns_test[1].offices[0].max_weight);
    assert('d' == towns_test[1].offices[0].packages[0].id);
    assert(1 == towns_test[1].offices[0].packages[0].weight);
    assert('e' == towns_test[1].offices[0].packages[1].id);
    assert(2 == towns_test[1].offices[0].packages[1].weight);
    assert('f' == towns_test[1].offices[0].packages[2].id);
    assert(3 == towns_test[1].offices[0].packages[2].weight);
    assert('h' == towns_test[1].offices[0].packages[3].id);
    assert(4 == towns_test[1].offices[0].packages[3].weight);
}

// Tests the send_all_acceptable_package() function
void test_send_all_acceptable_packages() {
    // An array of towns where the source office's packages weights are less than the target office's weight range.
    town* towns_test_source_weight_less_than_target_range = initialize_towns(2, (char[2]){'A', 'B'},
                                                                (int[2]){1, 1},
                                                                (int[6]){2, 1, 2, 2, 3, 5},
                                                                (char[4]){'a', 'b', 'c', 'd'},
                                                                (int[4]){1, 2, 3, 5},
                                                                1);

    // Tests to check if the source office's packages that are less than the target office's package weight range are returned to the source office.
    send_all_acceptable_packages(&towns_test_source_weight_less_than_target_range[0], 0, &towns_test_source_weight_less_than_target_range[1], 0);
    assert('a' == towns_test_source_weight_less_than_target_range[0].offices[0].packages[0].id);
    assert('b' == towns_test_source_weight_less_than_target_range[0].offices[0].packages[1].id);
    assert('c' == towns_test_source_weight_less_than_target_range[1].offices[0].packages[0].id);
    assert('d' == towns_test_source_weight_less_than_target_range[1].offices[0].packages[1].id);

    // An array of towns where the source office's packages weights are greater than the target office's weight range.
    town* towns_test_source_weight_greater_than_target_range = initialize_towns(2, (char[2]){'A', 'B'},
                                                                          (int[2]){1, 1},
                                                                          (int[6]){2, 3, 5, 2, 1, 2},
                                                                          (char[4]){'a', 'b', 'c', 'd'},
                                                                          (int[4]){3, 5, 1, 2},
                                                                          1);

    // Tests to check if the source office's packages that are greater than the target's office package weight range are returned to the source office.
    send_all_acceptable_packages(&towns_test_source_weight_greater_than_target_range[0], 0, &towns_test_source_weight_greater_than_target_range[1], 0);
    assert('a' == towns_test_source_weight_greater_than_target_range[0].offices[0].packages[0].id);
    assert('b' == towns_test_source_weight_greater_than_target_range[0].offices[0].packages[1].id);
    assert('c' == towns_test_source_weight_greater_than_target_range[1].offices[0].packages[0].id);
    assert('d' == towns_test_source_weight_greater_than_target_range[1].offices[0].packages[1].id);

    // An array of towns where the source office's packages weights are within the target office's weight range.
    town* towns_test_source_weight_within_target_range = initialize_towns(2, (char[2]){'A', 'B'},
                                                                      (int[2]){1, 1},
                                                                      (int[6]){2, 1, 3, 2, 3, 5},
                                                                      (char[4]){'a', 'b', 'c', 'd'},
                                                                      (int[4]){3, 3, 4, 5},
                                                                      1);

    // Tests to check if the source office's packages that are within the target's office package weight range are received by the target office and that the source package array is empty.
    send_all_acceptable_packages(&towns_test_source_weight_within_target_range[0], 0, &towns_test_source_weight_within_target_range[1], 0);
    assert('c' == towns_test_source_weight_within_target_range[1].offices[0].packages[0].id);
    assert('d' == towns_test_source_weight_within_target_range[1].offices[0].packages[1].id);
    assert('a' == towns_test_source_weight_within_target_range[1].offices[0].packages[2].id);
    assert('b' == towns_test_source_weight_within_target_range[1].offices[0].packages[3].id);
    assert(NULL == towns_test_source_weight_within_target_range[0].offices[0].packages);

}

int main() {
    town* towns_test = initialize_towns(2, (char[2]){'A', 'B'},
                                  (int[2]){2, 1},
                                  (int[9]){2, 1, 3, 1, 2, 4, 4, 1, 4},
                                  (char[7]){'a', 'b', 'c', 'd', 'e', 'f', 'h'},
                                  (int[7]){2, 3, 2, 1, 2, 3, 4},
                                  1);

    // Testing the manual initialization of an array of towns.
    test_initialize_towns(towns_test);
    // Testing the send_all_acceptable_packages() function.
    test_send_all_acceptable_packages();

    int towns_count = malloc(sizeof(int));
    scanf("%d", &towns_count);
    town* towns = initialize_towns(towns_count, NULL, NULL, NULL, NULL, NULL, 0);

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
