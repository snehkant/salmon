#ifndef __SINGLE_CELL_PROTOCOLS_HPP__
#define __SINGLE_CELL_PROTOCOLS_HPP__

#include <string>

#include "AlevinOpts.hpp"

namespace alevin{
  namespace protocols {

    struct Rule{
      Rule(){}
      Rule(uint32_t barcodeLength_,
           uint32_t umiLength_,
           BarcodeEnd end_,
           uint32_t maxValue_):
        barcodeLength(barcodeLength_),
        umiLength(umiLength_),
        end(end_),
        maxValue(maxValue_){}
      uint32_t barcodeLength, umiLength, maxValue;
      BarcodeEnd end;
    };

    struct DropSeq : Rule{
      //Drop-Seq starts from 5 end with 12 length
      //barcode and 8 length umi & iupac can be
      //changed
      DropSeq(): Rule(12, 8, BarcodeEnd::FIVE, 16777216){}
    };

    struct InDrop : Rule{
        //InDrop starts from 5end with variable
        //length barcodes so provide the full
        // length of the barcod eincluding w1.
        // UMI length is 6
      InDrop(): Rule(42, 6, BarcodeEnd::FIVE, 22347776){}

      std::string w1;
      void setW1(std::string& w1_){
        w1 = w1_;
      }
    };

    struct Chromium : Rule{
      Chromium(): Rule(16, 10, BarcodeEnd::FIVE, 4294967295){}
    };

    struct Gemcode : Rule{
      Gemcode(): Rule(14, 10, BarcodeEnd::FIVE, 268435456){}
    };

    //dummy class
    struct Custom : Rule{
      Custom() : Rule(0,0,BarcodeEnd::THREE,0){}
    };
  }
}

#endif
