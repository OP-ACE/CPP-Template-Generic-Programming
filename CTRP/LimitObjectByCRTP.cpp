// template <class ToBeLimited, uint32_t maxInstance>
// struct LimitNoOfInstances {
//     static atomic<uint32_t> cnt;

//     LimitNoOfInstances() {
//         if (cnt >= maxInstance)
//             throw logic_error{"Too Many Instances"};
//         ++cnt;
//     }
//     ~LimitNoOfInstances() { --cnt; }
// }; // Copy, move & other sanity checks to be complete

// struct One : LimitNoOfInstances<One, 1> {};
// struct Two : LimitNoOfInstances<Two, 2> {};

// template <class T, uint32_t maxNoOfInstace>
// atomic<uint32_t> LimitNoOfInstances<T, maxNoOfInstace>::cnt(0);


// void use_case() {
//     Two _2_0, _2_1;

//     try {
//         One _1_0, _1_1;
//     } catch (exception &e) {
//         cout << e.what() << endl;
//     }
// }