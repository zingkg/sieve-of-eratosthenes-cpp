#include "catch.hpp"

#include "Sieve_of_Eratosthenes/SieveOfEratosthenes.hpp"

TEST_CASE("Sieve of Eratosthenes", "[SieveOfEratosthenes]") {
    SECTION("getPrimes should return a vector of primes correctly") {
        const SieveOfEratosthenes constantSieve(11u);
        const std::vector<uint32_t> constantSievePrimes = constantSieve.getPrimes();
        REQUIRE(constantSievePrimes.size() == 5);
        REQUIRE(constantSievePrimes[0] == 2);
        REQUIRE(constantSievePrimes[1] == 3);
        REQUIRE(constantSievePrimes[2] == 5);
        REQUIRE(constantSievePrimes[3] == 7);
        REQUIRE(constantSievePrimes[4] == 11);

        SieveOfEratosthenes resizingSieve(11u);
        REQUIRE(resizingSieve.getPrimes().size() == 5);
        resizingSieve.getPrimes(20);
        std::vector<uint32_t> resizingSievePrimes = resizingSieve.getPrimes();
        REQUIRE(resizingSievePrimes.size() == 8);
        REQUIRE(resizingSievePrimes[0] == 2);
        REQUIRE(resizingSievePrimes[1] == 3);
        REQUIRE(resizingSievePrimes[2] == 5);
        REQUIRE(resizingSievePrimes[3] == 7);
        REQUIRE(resizingSievePrimes[4] == 11);
        REQUIRE(resizingSievePrimes[5] == 13);
        REQUIRE(resizingSievePrimes[6] == 17);
        REQUIRE(resizingSievePrimes[7] == 19);
    }
}
