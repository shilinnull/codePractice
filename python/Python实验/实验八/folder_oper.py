import os
import shutil
print("=== os模块基础操作 ===")
current_dir = os.getcwd()
print(f"当前工作目录: {current_dir}")
all_items = os.listdir(current_dir)
print(f"当前目录内容: {all_items}")
py_files = [item for item in all_items if item.endswith(".py")]
print(f"当前目录下的.py文件: {py_files}")

print("\n=== 创建与删除文件夹 ===")
test_dir1 = "test_folder1"
if not os.path.exists(test_dir1):
    os.mkdir(test_dir1)
    print(f"创建文件夹: {test_dir1}")
else:
    print(f"文件夹{test_dir1}已存在")

test_dir2 = "test_folder2/sub_folder"
if not os.path.exists(test_dir2):
    os.makedirs(test_dir2)
    print(f"创建多级文件夹: {test_dir2}")
else:
    print(f"多级文件夹{test_dir2}已存在")

with open(os.path.join(test_dir1, "empty.txt"), "w", encoding="utf-8") as f:
    f.write("测试文件")

if os.path.exists(test_dir1):
    shutil.rmtree(test_dir1)
    print(f"删除非空文件夹: {test_dir1}")

print("\n=== 文件复制与移动 ===")
src_file = "test_write.txt"
dst_dir = "test_folder2"
dst_file = os.path.join(dst_dir, "copied_file.txt")
if os.path.exists(src_file) and os.path.exists(dst_dir):
    shutil.copy(src_file, dst_file)
    print(f"复制文件: {src_file} -> {dst_file}")

move_src = dst_file
move_dst = os.path.join(dst_dir, "moved_file.txt")
if os.path.exists(move_src):
    shutil.move(move_src, move_dst)
    print(f"移动文件: {move_src} -> {move_dst}")
dst_file = move_dst     # 这里需要修改才能正确
print("\n=== os.path模块操作 ===")
test_path = dst_file
print(f"路径: {test_path}")
print(f"是否存在: {os.path.exists(test_path)}")
print(f"是否为文件: {os.path.isfile(test_path)}")
print(f"是否为文件夹: {os.path.isdir(test_path)}")
print(f"文件大小（字节）: {os.path.getsize(test_path)}")
print(f"绝对路径: {os.path.abspath(test_path)}")
print(f"路径拼接: {os.path.join('a', 'b', 'c.txt')}")