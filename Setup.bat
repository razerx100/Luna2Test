if not exist Solution\ (
    mkdir .\Solution
)
cd .\Solution
cmake .. -G "Visual Studio 17 2022" -A x64 -DBRANCH=master -DGOOGLE_TEST_COMMIT_ID=06f44bc951046150f1348598854b211afdcf37fc