// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include <vector>
#include "benchmark/benchmark.h"
#include "src/utils/UnaryFilter.h"

namespace ape {
namespace bench {

//BENCHMARK(FilterEqInt32)->Apply(VarianceKernelBenchArgs)

static void BM_GT_INT32(benchmark::State& state) {
    auto filter = std::make_shared<Gt<int32_t>>();
    std::vector<int32_t> values{0,1,2,3,4,5,6,7,8,9};
    std::vector<char> out(values.size());
    filter->execute(values.data(), values.size(), 4, out.data());
}
BENCHMARK(BM_GT_INT32);

}  // namespace bench
}  // namespace ape
