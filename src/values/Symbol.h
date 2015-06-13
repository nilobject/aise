#pragma once
#include "Aise.h"
#include "Token.h"
#include "Value.h"

namespace Aise {
    class Symbol : public Value
    {
    public:
        Symbol(bool isTemplate, std::shared_ptr<Aise::Token> token);
        virtual ~Symbol();
        
		virtual std::string Description();
		virtual int Compare(std::shared_ptr<Value> to);
        
        std::shared_ptr<Aise::Token> Token() { return mToken; }
        std::string String() { return mToken->String(); }

		virtual Result EvaluateTemplate(std::shared_ptr<Aise::Binding> binding);
    private:
        std::shared_ptr<Aise::Token> mToken;
    };
	typedef std::shared_ptr<Symbol> SymbolPtr;
}