#pragma once

#include <goofit/GlobalCudaDefines.h>
#include <goofit/detail/Complex.h>

#include <thrust/functional.h>
#include <thrust/tuple.h>

namespace GooFit {

class SFCalculator : public thrust::unary_function<thrust::tuple<int, fptype *, int>, fpcomplex> {
  public:
    // Used to create the cached BW values.
    SFCalculator();
    void setDalitzId(int idx) { dalitzFuncId = idx; }
    void setSpinFactorId(int idx) { _spinfactor_i = idx; }
    __device__ auto operator()(thrust::tuple<int, fptype *, int> t) const -> fpcomplex;

  private:
    unsigned int dalitzFuncId;
    unsigned int _spinfactor_i{0};
};

} // namespace GooFit
