#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include <set>
using namespace llvm;


// References:
//      - http://llvm.org/docs/WritingAnLLVMPass.html#writing-an-llvm-pass
namespace {
    struct CheckPointerPass : public FunctionPass {
        static char ID;
        CheckPointerPass() : FunctionPass(ID) {}

        virtual bool runOnFunction(Function &function) override {
            errs() << "CheckPointerPass: [start]: " << function.getName() << "\n";
            for (auto &block : function) {
                for (auto &instruction : block) {
                    Type *type = instruction.getType();

                    // dereferncing using * operator
                    if (auto *loadinstr = dyn_cast<LoadInst>(&instruction)) {
                        if (loadinstr->getPointerOperand()->getType()->getContainedType(0)->isPointerTy())
                            errs() << "DEREF * " << loadinstr->getPointerOperand()->getName() << "\n";
                    }

                    // dereferencing using arrow syntax
                    if (auto gepinstr = dyn_cast<GetElementPtrInst>(&instruction)) {
                        if (gepinstr->getPointerOperand()->getType()->isPointerTy()) {
                            if (auto *loadinstr = dyn_cast<LoadInst>(gepinstr->getPointerOperand())) {
                                errs() << "DEREF " << gepinstr->getName() << " " << loadinstr->getPointerOperand()->getName() << "\n";
                            }
                        }
                    }

                    // pointer assignments
                    if (type->isPointerTy()) {
                        if (type->getContainedType(0)->isPointerTy()) {
                            errs() << "POINTER " << instruction.getName() << "\n";
                        }
                    }

                }
            }

            errs() << "CheckPointerPass: [  end]: " << function.getName() << "\n";
            // we haven't modified the code
            return false;
        }
    };
}

char CheckPointerPass::ID = 0;

static void registerCheckPointerPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
    PM.add(new CheckPointerPass());
}
static RegisterStandardPasses
    RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerCheckPointerPass);
