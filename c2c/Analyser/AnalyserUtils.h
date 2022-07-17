/* Copyright 2013-2022 Bas van den Berg
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANALYSER_UTILS_H
#define ANALYSER_UTILS_H

#include <string>
#include "AST/Type.h"
#include "AST/Expr.h"

namespace C2 {

class Decl;
class StringBuilder;
class TargetInfo;
class ASTContext;

class AnalyserUtils {
public:
    static void init(const TargetInfo& target_);
    static const char* fullName(const std::string& modName, const char* symname);

    static QualType getStructType(QualType Q);
    static QualType getPointerFromArray(ASTContext& context, QualType Q);
    static QualType getMinusType(QualType Q);
    static bool exprIsType(const Expr* E);
    static QualType UsualUnaryConversions(Expr* expr);
    static void SetConstantFlags(const Decl* D, Expr* expr);
    static bool isConstantBitOffset(const Expr* E);
    static StringBuilder& quotedField(StringBuilder &builder, IdentifierExpr *field);

    static uint64_t sizeOfStruct(StructTypeDecl* S, uint32_t* align);
    static uint64_t sizeOfUnion(StructTypeDecl* S, uint32_t* align);
    static uint64_t sizeOfType(QualType type, unsigned* alignment);

    static uint64_t offsetOfStructMember(const StructTypeDecl* S, unsigned index);

    static Expr* getInnerExprAddressOf(Expr* expr);

    static const Expr* ignoreParenEpr(const Expr* expr);

    static IdentifierExpr::RefKind globalDecl2RefKind(const Decl* D);
};

}

#endif

