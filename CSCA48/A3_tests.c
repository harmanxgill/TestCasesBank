#include<stdio.h>
#include<stdlib.h>
#include"ingredient_graph.c"

// Tests for Small Graph: Size 10

int main(){

    load_ingredients();
    intNode *head=NULL;

    printf("\nTest 1: RELATED K DISTANCE TESTS\n");

    // Test 1.1: 
    printf("\nTest 1.1: Related to 'medium shrimp' k-dist, k=2\n");
    head=related_k_dist(head,"medium shrimp",2,0);
    print_ingredients(head);
    head=deleteList(head);

    // Test 1.2: 
    printf("\nTest 1.2: Related to 'prepared horseradish' k-dist, k=3\n");
    head=related_k_dist(head,"prepared horseradish",3,0);
    print_ingredients(head);
    head=deleteList(head);

    // Test 1.3: 
    printf("\nTest 1.3: Related to 'turkey' k-dist, k=1\n");
    head=related_k_dist(head,"turkey",1,0);
    print_ingredients(head);
    head=deleteList(head);

    // Test 1.4: 
    printf("\nTest 1.4: Related to 'soymilk' k-dist, k=4\n");
    head=related_k_dist(head,"soymilk",4,0);
    print_ingredients(head);
    head=deleteList(head);

    // Test 1.5: 
    printf("\nTest 1.5: Related to 'tomato juice' k-dist, k=2\n");
    head=related_k_dist(head,"tomato juice",2,0);
    print_ingredients(head);
    head=deleteList(head);

    // Test 1.6:
    printf("\nTest 1.6: Related to 'fresh breadcrumbs' k-dist, k=0\n");
    head=related_k_dist(head,"fresh breadcrumbs",0,0);
    print_ingredients(head);
    head=deleteList(head);

    printf("\nTest 2: RELATED WITH RESTRICTIONS TESTS\n");
    
    // Test 2.1
    printf("\nTest 2.1:  Related with restrictions, 'quinoa', 'tomato juice', k_source=3, k_dest=2\n");
    head=related_with_restrictions("quinoa","tomato juice",3,2);
    print_ingredients(head);
    head=deleteList(head);

    // Test 2.2
    printf("\nTest 2.2:  Related with restrictions, 'medium shrimp', 'prepared horseradish', k_source=2, k_dest=1\n");
    head=related_with_restrictions("medium shrimp","prepared horseradish",2,1);
    print_ingredients(head);
    head=deleteList(head);

    // Test 2.3
    printf("\nTest 2.3:  Related with restrictions, 'turkey', 'gruyere cheese', k_source=4, k_dest=3\n");
    head=related_with_restrictions("turkey","gruyere cheese",4,3);
    print_ingredients(head);
    head=deleteList(head);

    // Test 2.4
    printf("\nTest 2.4:  Related with restrictions, 'fresh breadcrumbs', 'artichoke hearts', k_source=2, k_dest=0\n");
    head=related_with_restrictions("fresh breadcrumbs","artichoke hearts",2,0);
    print_ingredients(head);
    head=deleteList(head);

    // Test 2.5
    printf("\nTest 2.5:  Related with restrictions, 'soymilk', 'sunflower seeds', k_source=3, k_dest=1\n");
    head=related_with_restrictions("soymilk","sunflower seeds",3,1);
    print_ingredients(head);
    head=deleteList(head);

    // Test 2.6
    printf("\nTest 2.6:  Related with restrictions, 'medium shrimp', 'medium shrimp', k_source=3, k_dest=3\n");
    head=related_with_restrictions("medium shrimp","medium shrimp",3,3);
    print_ingredients(head);
    head=deleteList(head);

    printf("\nTest 3: SUBSTITUTE TESTS\n");

    // Test 3.1
    printf("\nTest 3.1:  Substitute 'medium shrimp'\n");
    char recipe1[10][MAX_STR_LEN]={"medium shrimp",
				 "sunflower seeds",
				 "fresh breadcrumbs",
				 "turkey",
				 "",
				 "",
				 "",
				 "",
				 "",
				 ""};
    substitute_ingredient(recipe1,"medium shrimp");
    for (int i=0; i<10; i++)
        if (strlen(recipe1[i])>0) printf("%s\n",recipe1[i]);

    // Test 3.2
    printf("\nTest 3.2:  Substitute 'soymilk'\n");
    char recipe2[10][MAX_STR_LEN]={"medium shrimp",
				 "sunflower seeds",
				 "fresh breadcrumbs",
				 "turkey",
				 "artichoke hearts",
				 "prepared horseradish",
				 "soymilk",
				 "gruyere cheese",
				 "quinoa",
				 ""};
    substitute_ingredient(recipe2,"soymilk");
    for (int i=0; i<10; i++)
        if (strlen(recipe2[i])>0) printf("%s\n",recipe2[i]);

    // Test 3.3
    printf("\nTest 3.3:  Substitute 'turkey'\n");
    char recipe3[10][MAX_STR_LEN]={"medium shrimp",
				 "sunflower seeds",
				 "fresh breadcrumbs",
				 "turkey",
				 "artichoke hearts",
				 "prepared horseradish",
				 "soymilk",
				 "gruyere cheese",
				 "quinoa",
				 "tomato juice"};
    substitute_ingredient(recipe3,"turkey");
    for (int i=0; i<10; i++)
        if (strlen(recipe3[i])>0) printf("%s\n",recipe3[i]);


    return 0;
}