cmake_minimum_required(VERSION 3.26)
project(Algorithms_and_DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(Heap_Sort)
include_directories(Infix_Postfix)
include_directories(ITMO_ALGO_DS/Queue_On_Vector__lIST)
include_directories(ITMO_ALGO_DS/Stack_On_Vector__List)
include_directories(Merge_Sort)

add_executable(Algorithms_and_DS
        "Codeforces round 882(div.2)/main.cpp"
        "Codeforces round 883(div.3)/main.cpp"
        "CSES/Dynamic Programming/Array Description/main.cpp"
        "CSES/Dynamic Programming/BookShop/main.cpp"
        "CSES/Dynamic Programming/Counting Towers/main.cpp"
        "CSES/Dynamic Programming/Elevator Rides/main.cpp"
        "CSES/Dynamic Programming/Grid Paths/main.cpp"
        "CSES/Dynamic Programming/Minimizing Coins/main.cpp"
        "CSES/Dynamic Programming/Projects/main.cpp"
        "CSES/Dynamic Programming/Rectangle Cutting/main.cpp"
        "CSES/Geometry/Line Segment Intersection/main.cpp"
        "CSES/Geometry/Point in Polygon/main.cpp"
        "CSES/Geometry/Pointer Location Test/main.cpp"
        "CSES/Geometry/PolygonLattice Points/main.cpp"
        CSES/Graphs/BuildingRoads/main.cpp
        "CSES/Graphs/Counting Rooms/main.cpp"
        CSES/Graphs/Labyrinth/main.cpp
        "CSES/Introductory Problems/ChessBoardAndQueens/main.cpp"
        "CSES/Introductory Problems/CreatingStrings/main.cpp"
        "CSES/Introductory Problems/Palindrome/main.cpp"
        "CSES/Introductory Problems/TowerOfHonoi/main.cpp"
        "CSES/Maths/Binomial Coefficients/main.cpp"
        CSES/Maths/Exponentiation/main.cpp
        "CSES/Maths/Josephus Queries/main.cpp"
        "CSES/Maths/Prime Multiples/main.cpp"
        "CSES/Sorting And Searching/Collecting Numbers 2/main.cpp"
        "CSES/Sorting And Searching/Factory Machines/main.cpp"
        "CSES/Sorting And Searching/Josephus Problem 2/main.cpp"
        "CSES/Sorting And Searching/Movie Festival/main.cpp"
        "CSES/Sorting And Searching/MovieFestival 2/main.cpp"
        "CSES/Sorting And Searching/Nested Ranges Check/main.cpp"
        "CSES/Sorting And Searching/Nested Ranges Count/main.cpp"
        "CSES/Sorting And Searching/Playlist/main.cpp"
        "CSES/Sorting And Searching/Room Allocation/main.cpp"
        "CSES/Sorting And Searching/SubArray Distinct Values/main.cpp"
        "CSES/Sorting And Searching/SubArraySum/main.cpp"
        "CSES/Sorting And Searching/Sum of Three Values/main.cpp"
        "CSES/Sorting And Searching/Traffic Lights/main.cpp"
        "CSES/String/Finding Border/main.cpp"
        "CSES/String/Finding Periods( Z function)/main.cpp"
        "CSES/String/String Matching(  Prefix function)/main.cpp"
        "CSES/String/Word Combination( Trie )/main.cpp"
        Heap_Sort/Heap.h
        Heap_Sort/main.cpp
        Infix_Postfix/ExprPart.cpp
        Infix_Postfix/ExprPart.h
        Infix_Postfix/Functions.cpp
        Infix_Postfix/Functions.h
        Infix_Postfix/main.cpp
        ITMO_ALGO_DS/Queue_On_Vector__lIST/Linked_List.h
        ITMO_ALGO_DS/Queue_On_Vector__lIST/main.cpp
        ITMO_ALGO_DS/Queue_On_Vector__lIST/Queue.h
        ITMO_ALGO_DS/Queue_On_Vector__lIST/Stack.h
        ITMO_ALGO_DS/Queue_On_Vector__lIST/Vector.h
        ITMO_ALGO_DS/Stack_On_Vector__List/Linked_List.h
        ITMO_ALGO_DS/Stack_On_Vector__List/main.cpp
        ITMO_ALGO_DS/Stack_On_Vector__List/Queue.h
        ITMO_ALGO_DS/Stack_On_Vector__List/Stack.h
        ITMO_ALGO_DS/Stack_On_Vector__List/Vector.h
        Merge_Sort/ListNode.h
        Merge_Sort/main.cpp
        Techiedelight/main.cpp)
