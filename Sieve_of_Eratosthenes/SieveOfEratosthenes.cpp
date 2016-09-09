#include "SieveOfEratosthenes.hpp"

#include <iostream>

SieveOfEratosthenes::SieveOfEratosthenes(const std::uint32_t x) {
    size = x + 1;
    primeStatus = initializePrimeArray(size);
    calculatePrimes();
}

SieveOfEratosthenes::SieveOfEratosthenes(const std::uint64_t x) {
    size = x + 1;
    primeStatus = initializePrimeArray(size);
    calculatePrimes();
}

SieveOfEratosthenes::~SieveOfEratosthenes() {
}

std::vector<uint32_t> SieveOfEratosthenes::getPrimes() const {
    return retrievePrimes();
}

std::vector<uint32_t> SieveOfEratosthenes::getPrimes(const uint32_t x) {
    if (size < x)
        resize(x);

    if (!calculated)
        calculatePrimes();

    return retrievePrimes();
}

void SieveOfEratosthenes::printPrimes() const {
    const std::vector<uint32_t> primes = retrievePrimes();
    std::cout << "printing" << std::endl;
    for (const auto &prime : primes)
        std::cout << prime << " ";

    std::cout << std::endl;
}

void SieveOfEratosthenes::resize(const std::uint32_t x) {
    size = x + 1;
    std::unique_ptr<PrimeStatus[]> newPrimeStatus = initializePrimeArray(size);
    primeStatus = std::move(newPrimeStatus);
    calculated = false;
}

void SieveOfEratosthenes::calculatePrimes() {
    for (std::uint32_t i = 2; i < size; i++) {
        if (primeStatus[i] == PrimeStatus::UNDISCOVERED) {
            const bool isPrime = testPrime(i);
            if (isPrime) {
                primeStatus[i] = PrimeStatus::PRIME;
                for (std::uint32_t j = 2; i * j < size; j++)
                    primeStatus[i * j] = PrimeStatus::NON_PRIME;
            }
        }
    }
    calculated = true;
}

bool SieveOfEratosthenes::testPrime(const uint32_t x) const {
    for (uint32_t i = 2; i < x; i++)
        if (x % i == 0)
            return false;

    return true;
}

std::vector<std::uint32_t> SieveOfEratosthenes::retrievePrimes() const {
    std::vector<std::uint32_t> primes;
    for (std::uint32_t i = 2; i < size; i++) {
        if (primeStatus[i] == PrimeStatus::PRIME)
            primes.push_back(i);
    }
    return primes;
}

std::unique_ptr<PrimeStatus[]> SieveOfEratosthenes::initializePrimeArray(const std::uint32_t size) {
    std::unique_ptr<PrimeStatus[]> array(new PrimeStatus[size]);
    for (std::uint32_t i = 0; i < size; i++)
        array[i] = PrimeStatus::UNDISCOVERED;

    return array;
}
