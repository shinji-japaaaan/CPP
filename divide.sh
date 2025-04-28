#!/bin/bash

# 出力先フォルダ名
output_folder="output_files"

# フォルダが存在しなければ作成
if [ ! -d "$output_folder" ]; then
    mkdir "$output_folder"
    echo "フォルダ '$output_folder' を作成しました。"
fi

output_base="${output_folder}/merged_part"
part_num=1
current_lines=0
max_lines=250

output_file="${output_base}_${part_num}.txt"
> "$output_file"

for file in *.txt; do
    if [ -f "$file" ]; then
        # ファイル名コメントを書く前に行数チェック
        if [ "$((current_lines + 1))" -gt "$max_lines" ]; then
            part_num=$((part_num + 1))
            output_file="${output_base}_${part_num}.txt"
            > "$output_file"
            current_lines=0
        fi
        echo "// File: $file" >> "$output_file"
        current_lines=$((current_lines + 1))

        # サブシェルを使わずに直接読む！
        while IFS= read -r line || [ -n "$line" ]; do
            if [ "$((current_lines + 1))" -gt "$max_lines" ]; then
                part_num=$((part_num + 1))
                output_file="${output_base}_${part_num}.txt"
                > "$output_file"
                current_lines=0
            fi
            echo "$line" >> "$output_file"
            current_lines=$((current_lines + 1))
        done < <(tail -n +11 "$file")  # ここがミソ！

        # ファイル間に空行を入れる前もチェック
        if [ "$((current_lines + 1))" -gt "$max_lines" ]; then
            part_num=$((part_num + 1))
            output_file="${output_base}_${part_num}.txt"
            > "$output_file"
            current_lines=0
        fi
        echo "" >> "$output_file"
        current_lines=$((current_lines + 1))
    fi
done

echo "分割完了！ファイルは '$output_folder' フォルダ内に保存されました。"
