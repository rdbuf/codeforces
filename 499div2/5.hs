import Data.List

unique = map head . group . sort

readInts :: IO [Int]
readInts = fmap (fmap read . words) getLine

main = do
    [n, k] <- readInts
    a <- fmap (fmap (`mod` k)) readInts

    let d = foldl1 gcd (unique a)
    let answer = unique $ fmap (\x -> x * d `mod` k) [0..k - 1]

    print . length $ answer
    putStrLn . unwords . map show $ answer
