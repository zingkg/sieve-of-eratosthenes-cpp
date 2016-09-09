#ifndef SIEVEOFERATOSTHENES_HPP
#define SIEVEOFERATOSTHENES_HPP

#include <cstdint>
#include <vector>
#include <memory>

enum class PrimeStatus : std::uint8_t {
    PRIME, NON_PRIME, UNDISCOVERED
};

class SieveOfEratosthenes {
public:
    SieveOfEratosthenes(const std::uint32_t x);
    SieveOfEratosthenes(const std::uint64_t x);
    virtual ~SieveOfEratosthenes();

    std::vector<std::uint32_t> getPrimes() const;
    std::vector<std::uint32_t> getPrimes(const std::uint32_t x);
    void printPrimes() const;
private:
    bool calculated;
    std::unique_ptr<PrimeStatus[]> primeStatus;
    std::uint32_t size;

    void resize(const std::uint32_t x);
    void calculatePrimes();
    bool testPrime(const std::uint32_t x) const;
    std::vector<std::uint32_t> retrievePrimes() const;
    std::unique_ptr<PrimeStatus[]> initializePrimeArray(const std::uint32_t size);
};

#endif /* SIEVEOFERATOSTHENES_HPP */
