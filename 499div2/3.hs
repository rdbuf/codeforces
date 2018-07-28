import Data.Ratio

main = do
    n <- fmap (read :: String -> Int) $ getLine
    m <- fmap (toRational . (read :: String -> Double)) $ getLine
    a <- fmap (map (toRational . (read :: String -> Double)) . words) $ getLine
    b <- fmap (map (toRational . (read :: String -> Double)) . words) $ getLine

    let d = product [1 - 1/x | x <- a] * product [1 - 1/x | x <- b]

    let answer = if d > 0 then show . fromRational $ m * (1 - d) / d
        else show (negate 1)

    putStrLn answer