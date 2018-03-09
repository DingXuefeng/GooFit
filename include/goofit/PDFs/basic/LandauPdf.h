#pragma once

#include <goofit/PDFs/GooPdf.h>

namespace GooFit {

class LandauPdf : public GooPdf {
  public:
    LandauPdf(std::string n, Observable _x, Variable mpv, Variable sigma);

    __host__ void recursiveSetIndices() override;

  private:
  private:
};
} // namespace GooFit