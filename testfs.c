#include "image.h"
#include "block.h"
#include "testfs.h"
#include <stdio.h>


#ifdef CTEST_ENABLE

void test_image_open(){
    CTEST_ASSERT(image_open("filesystem.img", 1) != -1, "image_open failed");
}

void test_image_close(){
    CTEST_ASSERT(image_close() != -1, "image_close failed");
}

void test_block_bread(){
    CTEST_ASSERT(bread(0, NULL) != -1, "bread failed");
}

void test_block_bwrite(){
    unsigned char buffer[BLOCK_SIZE];
    bwrite(0, buffer);
    CTEST_ASSERT(bwrite_error_flag != -1, "bwrite failed");
}

int main(){
    CTEST_VERBOSE(1);
    
    test_image_open();
    test_image_close();
    test_block_bread();
    test_block_bwrite();

    CTEST_RESULTS();
    CTEST_EXIT();
}

#else

int main(){
    
    // Test image open
    image_open("filesystem.img", 1);
    // Test image close
    image_close();
    
    unsigned char buffer[BLOCK_SIZE];
    // Test block bread
    bread(0, buffer);

    // Test block bwrite
    bwrite(0, buffer);

    // Print success message
    printf("Testfs is working\n");
    return 0;
}

#endif