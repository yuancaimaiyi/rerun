// NOTE: This file was autogenerated by re_types_builder; DO NOT EDIT.
// Based on "crates/re_types/definitions/rerun/testing/components/fuzzy.fbs"

#include "affix_fuzzer1.hpp"

#include "../datatypes/affix_fuzzer1.hpp"

#include <arrow/builder.h>
#include <arrow/table.h>
#include <arrow/type_fwd.h>
#include <rerun/arrow.hpp>

namespace rerun {
    namespace components {
        const char *AffixFuzzer1::NAME = "rerun.testing.components.AffixFuzzer1";

        const std::shared_ptr<arrow::DataType> &AffixFuzzer1::to_arrow_datatype() {
            static const auto datatype = rerun::datatypes::AffixFuzzer1::to_arrow_datatype();
            return datatype;
        }

        Result<std::shared_ptr<arrow::StructBuilder>> AffixFuzzer1::new_arrow_array_builder(
            arrow::MemoryPool *memory_pool
        ) {
            if (!memory_pool) {
                return Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(rerun::datatypes::AffixFuzzer1::new_arrow_array_builder(memory_pool).value
            );
        }

        Error AffixFuzzer1::fill_arrow_array_builder(
            arrow::StructBuilder *builder, const AffixFuzzer1 *elements, size_t num_elements
        ) {
            if (!builder) {
                return Error(ErrorCode::UnexpectedNullArgument, "Passed array builder is null.");
            }
            if (!elements) {
                return Error(
                    ErrorCode::UnexpectedNullArgument,
                    "Cannot serialize null pointer to arrow array."
                );
            }

            static_assert(sizeof(rerun::datatypes::AffixFuzzer1) == sizeof(AffixFuzzer1));
            RR_RETURN_NOT_OK(rerun::datatypes::AffixFuzzer1::fill_arrow_array_builder(
                builder,
                reinterpret_cast<const rerun::datatypes::AffixFuzzer1 *>(elements),
                num_elements
            ));

            return Error::ok();
        }

        Result<rerun::DataCell> AffixFuzzer1::to_data_cell(
            const AffixFuzzer1 *instances, size_t num_instances
        ) {
            // TODO(andreas): Allow configuring the memory pool.
            arrow::MemoryPool *pool = arrow::default_memory_pool();

            auto builder_result = AffixFuzzer1::new_arrow_array_builder(pool);
            RR_RETURN_NOT_OK(builder_result.error);
            auto builder = std::move(builder_result.value);
            if (instances && num_instances > 0) {
                RR_RETURN_NOT_OK(
                    AffixFuzzer1::fill_arrow_array_builder(builder.get(), instances, num_instances)
                );
            }
            std::shared_ptr<arrow::Array> array;
            ARROW_RETURN_NOT_OK(builder->Finish(&array));

            auto schema = arrow::schema(
                {arrow::field(AffixFuzzer1::NAME, AffixFuzzer1::to_arrow_datatype(), false)}
            );

            rerun::DataCell cell;
            cell.component_name = AffixFuzzer1::NAME;
            const auto ipc_result = rerun::ipc_from_table(*arrow::Table::Make(schema, {array}));
            RR_RETURN_NOT_OK(ipc_result.error);
            cell.buffer = std::move(ipc_result.value);

            return cell;
        }
    } // namespace components
} // namespace rerun
